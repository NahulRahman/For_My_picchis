%option noyywrap
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SymbolTable.h"
#define YYSTYPE SymbolInfo
#include "tac.tab.h"

void yyerror(const char* msg);



%}
DIGITS  [0-9]+
DOUBLE	{DIGITS}(\.{DIGITS})?
NAME	[a-zA-Z]
%%
[ \t]+ 	 { }
{DOUBLE} {
			SymbolInfo ob(string(yytext), "DOUBLE");
			//strcpy(yylval.cvar,yytext);
			yylval = (YYSTYPE) ob;
			return DOUBLE;
		 }
[-+*/=]  {
		    return *yytext;
	     }
"(" 	 {
			return *yytext;
		 }
")" 	 {
			return *yytext;
		 }
{NAME} 	 {
			SymbolInfo ob(string(yytext), "ID");
			//strcpy(yylval.cvar,yytext); // if use union
			yylval = (YYSTYPE) ob;
			return NAME;
		 }
\n 	     {
			return *yytext;
		 }	 

exit     {
			return 0;
		 }
.        {
			char msg[25];
			sprintf(msg," <%s>","invalid character",yytext);
			yyerror(msg);
		 }
%%