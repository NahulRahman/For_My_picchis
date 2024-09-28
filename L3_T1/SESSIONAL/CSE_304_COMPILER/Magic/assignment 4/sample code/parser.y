%{
#include<stdio.h>

extern FILE *yyin, *yyout;

int yylex(void);
void yyerror(char *str)
	{
	fprintf(yyout, "Error: %s\n", str);
	}



%}

%union{
    double dvar;
    char *name;
}

%type <dvar>expr 
%token <dvar>NUMBER NEWLINE <name>ID
%left '+' '-' 
%left '*' DIV

%%
stmt: line
| stmt line
;

line: expr NEWLINE 	{
			fprintf(yyout,"Rule Matched, %lf\n", $1);
			}
|ID NEWLINE	        {
			fprintf(yyout,"Rule Matched, %s", $1);
			}
|error NEWLINE      	{yyerrok;}
;

expr: NUMBER    	{$$=$1;} 
|expr '+' expr  	{$$=$1+$3;}
|expr '-' expr  	{$$=$1-$3;}
|expr '*' expr  	{$$=$1*$3;}
|expr DIV expr  	{if($3==0) yyerror("DIV by 0.");
                	else $$=$1/$3;}
;

%%

int main(){
	yyin=fopen("input.txt", "r");
	yyout=fopen("output.txt", "w");
    yyparse();
}