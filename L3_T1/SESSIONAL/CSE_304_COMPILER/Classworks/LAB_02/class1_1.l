%option noyywrap
%{
#include<stdio.h>
int count=0;
int line=0; 
%}

Start [a-zA-z_]
ID {Start}[a-zA-z_0-9]+
NUM [0-9]+

%%

int {fprintf(yyout,"<Keyword, Lexeme=%s,Length=%d\n>",yytext,yyleng);}
{ID} {fprintf(yyout,"<ID, Lexeme=%s,Length=%d\n>",yytext,yyleng);}
{NUM} {fprintf(yyout,"<NUM, Lexeme=%s,Length=%d\n>",yytext,yyleng);}
.*  {printf("other pattern"); count++;}

%%

int main(){
	yyin = fopen("in.txt","r");
	yyout = fopen("op.txt","w");
	yylex();
	printf("Total other pattern=%d\n",count);
	return 0;
}

