%option noyywrap

%{
    #include <bits/stdc++.h>
    #include "symbolTable.h"
    #include "parser.tab.h"
%}

ws          [ \t]
digit       [0-9]
exp         ([Ee][-+]?{digit}+)?
integer     {digit}+{exp}
float       ({digit}+)?\.{digit}+{exp}
letter      [A-Za-z_]
variable    {letter}({digit}|{letter})*

%%
\n              {return NEWLINE;}
{ws}            {}
"int"           {return INT;}
"main"          {return MAIN;}
"("             {return LPARAN;}
")"             {return RPARAN;}
"{"             {return LCURL;}
"}"             {return RCURL;}
"["             {return LTHIRD;}
"]"             {return RTHIRD;}
"/"             {return DIVOP;}
"*"             {return MULOP;}
"%"             {return MODOP;}
"+"             {return PLUS;}
"-"             {return MINUS;}
">"             {return GRTTHAN;}
"<"             {return LESSTHAN;}
"||"            {return LOR;}
"&&"            {return LAND;}
"="             {return ASSOP;}
";"             {return SEMICOLON;}
","             {return COMMA;}
{variable}      {strcpy(yylval.cvar, yytext);
                 return ID;}
{float}         {strcpy(yylval.cvar, yytext);
                 return FLOAT;}
{integer}       {strcpy(yylval.cvar, yytext);
                 return INTEGER;}
%%


