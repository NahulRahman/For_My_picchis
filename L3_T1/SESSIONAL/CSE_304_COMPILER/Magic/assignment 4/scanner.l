%option noyywrap

%{
#include<bits/stdc++.h>
using namespace std;
char* token_name;
double num;
ofstream LOG("log.txt");
ofstream LOG_ERROR("log_error.txt");
#include"parser.tab.h"

%}

KEYWORD if|while|do|break|void|return
INTEGER [0-9]+
FLOATING_POINT [0-9]*\.({INTEGER}([Ee]?[+-]?{INTEGER}))
NUMBER ({INTEGER}|{FLOATING_POINT})[^A-Za-z_]
IDENTIFIER [_A-Za-z_]+[A-Za-z0-9_]*

%%

[\n]+  	     {return NEWLINE;}

[ ]+		 {}

{KEYWORD}    {}

exit 		 {exit(0);}

int 		 {return INT;}	

float        {return FLOAT;}

double       {return DOUBLE;}

{IDENTIFIER}  { 
	           token_name=yytext; 
               return ID;
			   }

{INTEGER}	  {
	          char* p=yytext;
			  string s=string(p);
			  num = stod(s);
	          return CONST_INT;
			 }

;           {return SEMICOLON;}

,           {return COMMA;}

\[		     {return LTHIRD;}

\]		     {return RTHIRD;}

=		     {return ASSIGNOP;}

\*		     {return MULOP;}

\/           {return DIVOP;}

%		     {return MODOP;}

\+		     {return ADDOP;}

-		     {return SUBOP;}

\&\&|\|\|	 {return LOGICOP;}

\(		     {return LPAREN;}

\)		     {return RPAREN;}

%%