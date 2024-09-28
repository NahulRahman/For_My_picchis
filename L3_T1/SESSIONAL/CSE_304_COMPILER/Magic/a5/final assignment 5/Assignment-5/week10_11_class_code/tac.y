%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SymbolTable.h"
#define YYSTYPE SymbolInfo

int yylex(void);
int t_count = 1;
char * str;
FILE *outFile;


void yyerror(const char *s)
{
	fprintf(stderr,"%s\n",s);
	return;
}

char* getTemp(int i)
{
    char *ret = (char*) malloc(15);
    sprintf(ret, "t%d", i);
	return ret;
}



%}

%error-verbose
%token  DOUBLE
%token NAME
%token '\n'



%right '='
%left '+' '-'
%left '*' 
%left '/'
%left '(' ')'


%%
program: program line		{	}
	| line					{   }
	;
line:
	expr 	'\n' 		    {	
								t_count = 1;	
								printf("\t\n");
							}
	| NAME '=' expr '\n' 	{				
								t_count-=1;
								str = getTemp(t_count);
								SymbolInfo 	obj1(string(str), "");					
								$$=obj1;
								cout<<$1.getSymbol()<<" = "<<$3.getSymbol()<<endl;

								/* following code for using union
								str = getTemp(t_count);
								strcpy($$, str);
								printf("%s = %s", $$, $1);
								*/

								t_count=1;
								
								
							}
	;
expr:
	expr '+' expr 			{ 
								str = getTemp(t_count);
								SymbolInfo 	obj1(string(str), "");					
								$$=obj1;
								cout<<$$.getSymbol()<<" = "<<$1.getSymbol()<<" + "<<$3.getSymbol()<<endl;
								
								/*
								// 3 Address code using union {char cvar[10];}
								
								str = getTemp(t_count);
								strcpy($$,str);
								printf("%s = %s + %s\n",$$,$1,$3);
								*/
								// asm code
								fprintf(outFile, "MOV ax, %s\n", $1.getSymbol().c_str()); // check documentation for c_str() function
								fprintf(outFile, "MOV bx, %s\n", $3.getSymbol().c_str()); // c_str() used to have fprintf compatible string
								fprintf(outFile, "ADD ax, bx\n");
								fprintf(outFile, "MOV %s, ax\n", $$.getSymbol().c_str());
								

								t_count++;
								
								

							}
	|term				 {
							$$=$1;
							//strcpy($$, $1);
						}
;
term: NAME 				{
							$$=$1;
							//strcpy($$, $1);
						}
	| DOUBLE {}
	
	;

%%


int main(void)
{
	outFile=fopen("out.txt", "a");
	yyparse();
	return 0;
}