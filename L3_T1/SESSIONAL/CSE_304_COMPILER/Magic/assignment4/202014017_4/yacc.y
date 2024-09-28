%{

#include<stdio.h>
#include<fstream>
#include<cstdio>   
#include <bits/stdc++.h>
#include "symbolTable.h"
extern FILE *yyin, *yyout;

int yylex(void);

void yyerror(const char *s){
	fprintf(yyout,"ERROR: %s\n", s);	
	}
	
int l = 1;

int yylex(void);
%}

%token ID LPARAN RPARAN INT  
%token NUM 
%token NEWLINE  
%token SEMICOLON 
%token COMMA 
%token LTHIRD 
%token RTHIRD 
%right ASSOP 
%left MULOP DIVOP MODOP 
%left MINUS PLUS GRTTHAN LESSTHAN LAND LOR 


%%
stmt:stmt unit 
|unit
;
unit:var_decl NEWLINE {l++;}
|expr_decl NEWLINE 	{l++;}
|error NEWLINE {l++;yyerror;} 
;
var_decl:type_spec decl_list SEMICOLON {fprintf(yyout,"Line Number: %d \nvar_decl:type_spec decl_list SEMICOLON\n",l);}
;
type_spec:INT {fprintf(yyout,"Line Number: %d\ntype_spec:INT\n",l);}
;
decl_list:decl_list COMMA term {fprintf(yyout,"Line Number: %d\ndecl_list:decl_list:decl_list COMMA term\n",l);}
|decl_list COMMA term LTHIRD NUM RTHIRD {fprintf(yyout,"Line Number: %d\ndecl_list:decl_list COMMA term LTHIRD NUM RTHIRD\n",l);}
|term {fprintf(yyout,"Line Number: %d\ndecl_list:term\n",l);}
|term LTHIRD NUM RTHIRD {fprintf(yyout,"Line Number: %d\ndecl_list:term LTHIRD NUM RTHIRD\n",l);}
|ass_list {fprintf(yyout,"Line Number: %d\ndecl_list:ass_list\n",l);}
;
ass_list:term ASSOP expr {fprintf(yyout,"Line Number: %d\nass_list:term ASSOP expr\n",l);}
;
expr:NUM {fprintf(yyout,"Line Number: %d\nexpr:NUM\n",l);}
|expr PLUS expr {fprintf(yyout,"Line Number: %d\nexpr:expr PLUS expr\n",l);}
|expr MULOP expr {fprintf(yyout,"Line Number: %d\nexpr:expr MULOP expr\n",l);}
|expr DIVOP expr {fprintf(yyout,"Line Number: %d\nexpr:expr DIVOP expr\n",l);}
|expr MODOP expr {fprintf(yyout,"Line Number: %d\nexpr:expr MODOP expr\n",l);}
|expr MINUS expr {fprintf(yyout,"Line Number: %d\nexpr:expr MINUS expr\n",l);}
|expr GRTTHAN expr {fprintf(yyout,"Line Number: %d\nexpr:expr GRTTHAN expr\n",l);}
|expr LESSTHAN expr {fprintf(yyout,"Line Number: %d\nexpr:expr LESSTHAN expr\n",l);}
|expr LAND expr {fprintf(yyout,"Line Number: %d\nexpr:expr LAND expr\n",l);}
|expr LOR expr {fprintf(yyout,"Line Number: %d\nexpr:expr LOR expr\n",l);}
|LPARAN expr RPARAN {fprintf(yyout,"Line Number: %d\nexpr:LPARAN expr RPARAN\n",l);}
|term {fprintf(yyout,"Line Number: %d\nexpr:term\n",l);}
;
term:ID {fprintf(yyout,"Line Number: %d\nterm:ID\n",l);}
;
expr_decl:term ASSOP expr SEMICOLON {fprintf(yyout,"Line Number: %d\nexpr_decl:term ASSOP expr SEMICOLON\n",l);}
;
%%

int main()
{
yyin=fopen("in.txt", "r");
yyout=fopen("log_error.txt", "w");
yyparse();
}