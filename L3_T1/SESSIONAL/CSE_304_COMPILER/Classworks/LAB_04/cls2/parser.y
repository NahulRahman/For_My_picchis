%{
#include<stdio.h>
//#define YYSTYPE double
int yylex();
void yyerror(const char *str){
printf("error.. %s\n", str);
}
%}

%union{
	double ivar;
	char *cvar;

}

%type <dvar>expr
%token NEWLINE <dvar>NUMBER <cvar>ID
%left '+' SUB
%left '*' '/'

%%
stmt: stmt line
| line
;

line: expr NEWLINE {printf("Rule matched. %lf \n", $1);}
| ID NEWLINE {printf("Rule matched. %s\n", $1);}
| error NEWLINE {yyerrok;}
;

expr: expr '+' expr	{$$=$1+$3;}
| expr SUB expr		{$$=$1-$3;}
| expr '*' expr		{if ($3==0) yyerror("Div by 0."s\n);
			else $$=$1*$3;}
| expr '/' expr		{$$=$1/$3;}
| NUMBER
;

%%

main(){
	yyparse();
}