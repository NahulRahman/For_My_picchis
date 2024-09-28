%option noyywrap
%{
#include "parser.tab.h"
%}

%%
[\n]    	{return NEWLINE;}
[0-9]+  	{yylval.dvar=atoi(yytext); 
        	return NUMBER;}
[A-Za-z]+   	{yylval.name=yytext;
            	return ID;}        
[-+*]   	{return *yytext;}
[/]     	{return DIV;}

%%
