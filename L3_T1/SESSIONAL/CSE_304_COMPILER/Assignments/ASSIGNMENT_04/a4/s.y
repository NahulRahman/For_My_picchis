%{
#include <stdio.h>
#include <stdlib.h>
#include "cls1.h"
#define YYSTYPE Symbolinfo
int yylex();
void yyerror(const char* str) {
        printf("Error: %s\n", str);
}
FILE * ir, *asmb, *symbol_table;
extern FILE *yyin;
extern Symboltable uable;  

int temp_count = 1;

char* newTemp(){
	char* temp;
	temp = (char*) malloc(15*sizeof(char));
	sprintf(temp, "t%d", temp_count);
	temp_count++;
	return temp;
}

%}

%token ID ADDOP MULOP SUBOP DIVOP MODOP ASSOP LPAREN RPAREN SEMICOLON LCURL RCURL INT CONST_INT CONST_FLOAT MAIN
%right ASSOP
%left ADDOP SUBOP
%left MULOP DIVOP MODOP

%%

prog: MAIN LPAREN RPAREN LCURL stmt RCURL 
;

stmt: stmt unit 
    | unit 
;

unit: var_decl 
    | expr_decl 
;

var_decl : type_spec decl_list SEMICOLON 
;

type_spec: INT
;
 
decl_list: term 
;


expr	: NUM 
	| expr ADDOP expr {
    		char* temp = newTemp();
    		$$ = Symbolinfo(temp, "Temp");
    		fprintf(ir, "%s = %s + %s\n", temp, $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV BX, %s\nADD AX, BX\nMOV [%s], AX\n\n\n", $1.getsymbol().c_str(), $3.getsymbol().c_str(), temp);}
	| expr SUBOP expr { 
    		char* temp = newTemp();
    		$$ = Symbolinfo(temp, "Temp");
    		fprintf(ir, "%s = %s - %s\n", temp, $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV BX, %s\nSUB AX, BX\nMOV [%s], AX\n\n\n", $1.getsymbol().c_str(), $3.getsymbol().c_str(), temp);}
	| expr MULOP expr {
    		char* temp = newTemp();
    		$$ = Symbolinfo(temp, "Temp");
    		fprintf(ir, "%s = %s * %s\n", temp, $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV BX, %s\nMUL BX\nMOV [%s], AX\n\n\n", $1.getsymbol().c_str(), $3.getsymbol().c_str(), temp);}
	| expr DIVOP expr { 
    		char* temp = newTemp();
    		$$ = Symbolinfo(temp, "Temp");
    		fprintf(ir, "%s = %s / %s\n", temp, $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV BX, %s\nDIV BX\nMOV [%s], AX\n\n\n", $1.getsymbol().c_str(), $3.getsymbol().c_str(), temp);}
	| expr MODOP expr { 
   		char* temp = newTemp();
    		$$ = Symbolinfo(temp, "Temp");
    		fprintf(ir, "%s = %s %% %s\n", temp, $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV BX, %s\nDIV BX\nMOV [%s], DX\n\n\n", $1.getsymbol().c_str(), $3.getsymbol().c_str(), temp);}  // MOD results in DX
	| LPAREN expr RPAREN {$$ = $2;}
	| term 
;


term: ID {
};

expr_decl: term ASSOP expr SEMICOLON {
    		fprintf(ir, "%s = %s\n", $1.getsymbol().c_str(), $3.getsymbol().c_str());
    		fprintf(asmb, "MOV AX, %s\nMOV [%s], AX\n\n\n", $3.getsymbol().c_str(), $1.getsymbol().c_str());}
;


NUM: CONST_INT
| CONST_FLOAT
;


%%

int main() {
    yyin = fopen("ip.txt","r");
    ir = fopen("code.ir", "w");
    asmb = fopen("code.asm", "w");
    //symbol_table = fopen("table.txt", "w");

    yyparse();

    fclose(ir);
    fclose(asmb);
    fclose(symbol_table);
    return 0;
}

