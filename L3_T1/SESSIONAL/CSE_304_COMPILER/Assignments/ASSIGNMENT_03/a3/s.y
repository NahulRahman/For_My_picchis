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

%union{
	double ivar;
	char *cvar;

}


%token ID INT CONST_INT FLOAT CONST_FLOAT DOUBLE  SEMICOLON 
%token ADDOP MINUS MULOP DIVOP MODOP ASSOP  
%token LCURL RCURL LTHIRD RTHIRD LOGICOP RELOP INCR COMMA
%left LPAREN RPAREN 
%left LCURL RCURL
%left LTHIRD RTHIRD 
%left ADDOP SUBOP 
%left MULOP DIVOP MODOP 
%left LOGICOP 
%left RELOP
%left COMMA 
%right ASSIGNOP  


%%

mul_stmt	: mul_stmt func_decl
		| func_decl
;
 
func_decl	: type_spec term LPAREN param_list RPAREN LCURL stmt RCURL 
					{fprintf(yyout,"Line Number: %d\n func_decl: type_spec term LPAREN param_list RPAREN LCURL stmt RCURL\n", line);}
;

stmt 		: stmt unit 		{fprintf(yyout,"Line Number: %d\n stmt: stmt unit\n", line);}
		| unit			{fprintf(yyout,"Line Number: %d\n stmt: unit\n", line);}
;

unit 		: var_decl 	{}
		| expr_decl  	{}
		| error			{yyerror("Syntax error");}
;

var_decl 	: type_spec decl_list SEMICOLON	{fprintf(yyout,"Line Number: %d\n var_decl:type_spec decl_list SEMICOLON\n",line);}
;

type_spec	: INT			{fprintf(yyout,"Line Number: %d\n type_spec:INT\n",line);}
		| FLOAT			{fprintf(yyout,"Line Number: %d\n type_spec:FLOAT\n",line);}
 		| DOUBLE		{fprintf(yyout,"Line Number: %d\n type_spec:DOUBLE\n",line);}
;

decl_list	: decl_list COMMA term				{fprintf(yyout,"Line Number: %d\n decl_list:decl_list:decl_list COMMA term\n",line);}
 		| decl_list COMMA term LTHIRD CONST_INT RTHIRD	{fprintf(yyout,"Line Number: %d\n decl_list:decl_list COMMA term LTHIRD CONST_INT RTHIRD\n",line);}
 		| term 						{fprintf(yyout,"Line Number: %d\n decl_list:term\n",line);}
 		| term LTHIRD CONST_INT RTHIRD			{fprintf(yyout,"Line Number: %d\n decl_list:term LTHIRD NUM RTHIRD\n",line);}
 		| ass_list					{fprintf(yyout,"Line Number: %d\n decl_list:ass_list\n",line);}
;

ass_list	: term ASSIGNOP expr	{fprintf(yyout,"Line Number: %d\n ass_list:term ASSOP expr\n",line);}
;

expr		: CONST_INT		{fprintf(yyout,"Line Number: %d\n expr:CONST_INT\n",line);}
		| CONST_FLOAT		{fprintf(yyout,"Line Number: %d\n expr:CONST_FLOAT\n",line);}
		| expr ADDOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr ADDOP expr\n",line);}
		| expr MINUS expr 	{fprintf(yyout,"Line Number: %d\n expr:expr MINUS expr\n",line);}
		| expr MULOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr MULOP expr\n",line);}
		| expr DIVOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr DIVOP expr\n",line);}
		| expr MODOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr MODOP expr\n",line);}
		| expr RELOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr RELOP expr\n",line);}
		| expr LOGICOP expr 	{fprintf(yyout,"Line Number: %d\n expr:expr LOGICOP expr\n",line);}
		| expr INCR expr 	{fprintf(yyout,"Line Number: %d\n expr:expr INCR expr\n",line);}
		| LPAREN expr RPAREN 	{fprintf(yyout,"Line Number: %d\n expr:LPAREN expr RPAREN\n",line);}
		| term			{fprintf(yyout,"Line Number: %d\n expr:term\n",line);}
;

term: ID {fprintf(yyout,"Line Number: %d\n expr:ID\n",line); };
expr_decl	: term ASSIGNOP expr SEMICOLON			{fprintf(yyout,"Line Number: %d\n expr_decl:term ASSOP expr SEMICOLON\n",line);}
;

param_list	: param_list COMMA param 			{fprintf(yyout, "Line Number: %d\n param_list: param_list COMMA param\n", line);}
          	| param 		 			{fprintf(yyout, "Line Number: %d\n param_list: param\n", line);}
		| /* empty */  // Allow no parameters
;

param		: type_spec term 	 			{fprintf(yyout, "Line Number: %d\n param: type_spec term\n", line);}
     		| type_spec term LTHIRD CONST_INT RTHIRD 	{fprintf(yyout, "Line Number: %d\n param: type_spec term LTHIRD CONST_INT RTHIRD\n", line);}
;

%%

main(){
	yyin=fopen("sample_input.txt","r");
	yyout=fopen("log_error.txt","w");
	freopen("log.txt", "w", stdout);
	yyparse();
	uable.print();
	return 0;
}