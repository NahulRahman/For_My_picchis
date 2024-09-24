%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cls1.h"
int yylex();
extern FILE *yyin, *yyout;
extern Symboltable uable;
int line = 1;

void yyerror(const char *str){
    fprintf(yyout, "Error: %s at line %d\n", str, line);
}
%}

%union {
    double ivar;
    char *cvar;
}

%token ID INT CONST_INT FLOAT CONST_FLOAT DOUBLE SEMICOLON 
%token ADDOP MINUS MULOP DIVOP MODOP ASSOP  
%token LCURL RCURL LTHIRD RTHIRD LOGICOP RELOP INCR COMMA
%token LPAREN RPAREN

%left ADDOP MINUS
%left MULOP DIVOP MODOP
%left RELOP LOGICOP
%left ASSOP
%nonassoc INCR 
%%

mul_stmt:
    mul_stmt func_decl
    | func_decl
;

func_decl: type_spec ID LPAREN param_list RPAREN LCURL stmt_list RCURL 
	{fprintf(yyout, "Line Number: %d\n func_decl: type_spec ID LPAREN param_list RPAREN LCURL stmt_list RCURL\n", line);}
;

stmt_list:
    stmt_list unit
    | unit
;

unit:
    var_decl
    | expr_decl 
    | error { yyerror("Syntax error"); }
;

var_decl:
    type_spec decl_list SEMICOLON {fprintf(yyout, "Line Number: %d\n var_decl: type_spec decl_list SEMICOLON\n", line);}
;

type_spec:
    INT { fprintf(yyout, "Line Number: %d\n type_spec: INT\n", line); }
    | FLOAT { fprintf(yyout, "Line Number: %d\n type_spec: FLOAT\n", line); }
    | DOUBLE { fprintf(yyout, "Line Number: %d\n type_spec: DOUBLE\n", line); }
;

decl_list	: decl_list COMMA term
 		| decl_list COMMA term LTHIRD CONST_INT RTHIRD
 		| term
 		| term LTHIRD CONST_INT RTHIRD
 		| ass_list
;

ass_list	: term ASSOP expr;


term	: ID
    	| ID LTHIRD CONST_INT RTHIRD
;

expr_decl :	expr SEMICOLON 	{fprintf(yyout, "Line Number: %d\n expr_decl : expr SEMICOLON\n", line);}
;

expr: 
    CONST_INT	{fprintf(yyout,"Line Number: %d\n expr:CONST_INT\n",line);}
    | CONST_FLOAT	{fprintf(yyout,"Line Number: %d\n expr:CONST_FLOAT\n",line);}
    | expr ADDOP expr	{ fprintf(yyout, "Line Number: %d\n expr: expr ADDOP expr\n", line);}
    | expr MINUS expr 	{ fprintf(yyout, "Line Number: %d\n expr: expr MINUS expr\n", line); }
    | expr MULOP expr {fprintf(yyout, "Line Number: %d\n expr: expr MULOP expr\n", line); }
    | expr DIVOP expr {fprintf(yyout, "Line Number: %d\n expr: expr DIVOP expr\n", line); }
    | expr MODOP expr {fprintf(yyout, "Line Number: %d\n expr: expr MODOP expr\n", line); }
    | expr RELOP expr {fprintf(yyout, "Line Number: %d\n expr: expr RELOP expr\n", line); }
    | expr LOGICOP expr {fprintf(yyout, "Line Number: %d\n expr: expr LOGICOP expr\n", line); }
    | expr INCR expr    {fprintf(yyout,"Line Number: %d\n expr:expr INCR expr\n",line);}
    | LPAREN expr RPAREN 	{fprintf(yyout,"Line Number: %d\n expr:LPAREN expr RPAREN\n",line);}
    | term { fprintf(yyout, "Line Number: %d\n expr: term\n", line); }
;

param_list:
    param_list COMMA param
    | param
    | /* empty */
;

param:
    type_spec ID
    | type_spec ID LTHIRD CONST_INT RTHIRD
;

%%

int main() {
    yyin = fopen("sample_input.txt", "r");
    yyout = fopen("log_error.txt", "w");
    freopen("log.txt", "w", stdout);
    yyparse();
    uable.print();
    return 0;
}
