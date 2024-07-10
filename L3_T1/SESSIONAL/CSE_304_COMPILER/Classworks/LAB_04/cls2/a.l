%option noyywrap
%{
#include "parser.tab.h"
#include<stdlib.h> 
%}

DIGITS [0-9]+
NUMBER	{DIGITS}(\.{DIGITS})?

%%

[\n]	{ return NEWLINE;}
[ \t]	{}
{NUMBER} {
	//sscanf(yytext, "%lf", &yylval);
	yylval.dvar=atof(yytext);
	return NUMBER;
		}
[+*/]	{return *yytext;}
[-]	{return SUB;}
[A-Za-z]+ { yylval.cvar=yytext;	return ID;}

%%

