%{
    #include <bits/stdc++.h>
    #include "symbolTable.h"


    extern FILE *yyin, *yyout;
    FILE *outFile;

    int temp_number = 1;
    SymbolInfo info;
    SymbolTable table;

    int yylex(void);
    string getTemp(int n){
        char c = n + '0';
        string temp = "t";
        temp += c;
        return temp;
    }
    
    void yyerror(const char *str){
        fprintf(yyout, "Error: %s\n", str);
    }    
%}




%union{
    char cvar[10];
}

%token INT MAIN LPARAN RPARAN LCURL RCURL NEWLINE SEMICOLON COMMA LTHIRD RTHIRD <cvar>ID <cvar>INTEGER <cvar>FLOAT
%type <cvar>expr term num
%right ASSOP
%left LOR
%left LAND
%nonassoc GRTTHAN LESSTHAN
%left PLUS MINUS
%left MULOP DIVOP MODOP

%left ADDOP MINUS
%left MULOP DIVOP MODOP



%%
prog: type_spec MAIN LPARAN RPARAN LCURL stmt RCURL
|type_spec ID LPARAN param_list RPARAN LCURL stmt RCURL prog
|NEWLINE prog
;

param_list: param_list COMMA type_spec ass_list
|type_spec ass_list
;

stmt: unit
| stmt unit
;

unit: NEWLINE           
|var_decl NEWLINE       
|expr_decl NEWLINE      {temp_number = 1;fprintf(yyout,"\n");}
|error NEWLINE          {yyerrok;fprintf(yyout,"\n");}
;

var_decl: type_spec decl_list SEMICOLON
;

expr_decl: term ASSOP expr SEMICOLON        {
                                                fprintf(yyout, "%s = %s\n", $1, $3);

                                                char *c = (char*) malloc(sizeof(char)*20);
                                                sprintf(c, "ST %s, %s\n\n", $1, $3);
                                                info.code += (string)c;
                                            }
;

type_spec: INT
;

decl_list: decl_list COMMA ass_list
|ass_list
;

ass_list: term ASSOP expr
|term LTHIRD INTEGER RTHIRD  
|term

term: ID                    {
                                table.INSERT((string)$1, "Identifier");
                            }
;

expr: LPARAN expr RPARAN    {  strcpy($$, $2);
                            }
| expr DIVOP expr           {
                                string t = getTemp(temp_number);
                                strcpy($$, t.c_str());
                                fprintf(yyout, "%s = %s / %s\n", $$, $1, $3);
                                temp_number++;

                                char *c = (char*) malloc(sizeof(char)*50);
                                sprintf(c, "MOV ax, %s\nMOV bx, %s\nDIV bx\nMOV %s, ax\n", $1, $3, t.c_str());
                                info.code += (string)c;
                            }
| expr MULOP expr           {
                                string t = getTemp(temp_number);
                                strcpy($$, t.c_str());
                                fprintf(yyout, "%s = %s * %s\n", $$, $1, $3);
                                temp_number++;

                                char *c = (char*) malloc(sizeof(char)*50);
                                sprintf(c, "MOV ax, %s\nMOV bx, %s\nMUL bx\nMOV %s, ax\n", $1, $3, t.c_str());
                                info.code += (string)c;
                            }
| expr MODOP expr           {
                                string t = getTemp(temp_number);
                                strcpy($$, t.c_str());
                                fprintf(yyout, "%s = %s % %s\n", $$, $1, $3);
                                temp_number++;

                                char *c = (char*) malloc(sizeof(char)*50);
                                sprintf(c, "MOV ax, %s\nMOV bx, %s\nDIV bx\nMOV %s, dx\n", $1, $3, t.c_str());
                                info.code += (string)c;
                            }
| expr PLUS expr            {
                                string t = getTemp(temp_number);
                                strcpy($$, t.c_str());
                                fprintf(yyout, "%s = %s + %s\n", $$, $1, $3);                                
                                temp_number++;

                                char *c = (char*) malloc(sizeof(char)*50);
                                sprintf(c, "MOV ax, %s\nMOV bx, %s\nADD ax, bx\nMOV %s, ax\n", $1, $3, t.c_str());
                                info.code += (string)c;
                            }
| expr MINUS expr           {
                                string t = getTemp(temp_number);
                                strcpy($$, t.c_str());
                                fprintf(yyout, "%s = %s - %s\n", $$, $1, $3);
                                temp_number++;

                                char *c = (char*) malloc(sizeof(char)*50);
                                sprintf(c, "MOV ax, %s\nMOV bx, %s\nSUB ax, bx\nMOV %s, ax\n", $1, $3, t.c_str());
                                info.code += (string)c;
                            }
| expr LOR expr
| expr LAND expr
| expr GRTTHAN expr
| expr LESSTHAN expr
| num                       {   
                                strcpy($$, $1);
                            }
| ID                        {   
                                strcpy($$, $1);
                            }
;

num: INTEGER
|FLOAT
;
%%

int main(){
    yyin = fopen("in.txt","r");
    yyout = fopen("code.ir","w");
    yyparse();
    outFile = fopen("code.asm","w");
    fprintf(outFile, "%s", info.code.c_str());
    table.print();
}