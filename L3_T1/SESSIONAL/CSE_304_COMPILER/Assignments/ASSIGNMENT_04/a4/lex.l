%option noyywrap
%{
#include <stdio.h>
#include <unistd.h>
#include "cls1.h"
#define YYSTYPE Symbolinfo
#include "s.tab.h"
void yyerror(const char* str);
Symboltable uable;
%}

letter          [A-Za-z]
integer		[0-9]+
floating	[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?
id              ({letter}|_)({letter}|{integer}|_)*

%%
"main"      {return MAIN;}
"int"		{return INT;}
{integer}	{yylval = Symbolinfo(yytext, "INTEGER"); return CONST_INT;}
{floating}   	{yylval = Symbolinfo(yytext, "FLOATING"); return CONST_FLOAT;}
{id}   		{yylval = Symbolinfo(yytext, "ID"); return ID;}
";"		{yylval = Symbolinfo(yytext, "SEMICOLON"); return SEMICOLON;}
"+"		{yylval = Symbolinfo(yytext, "ADDOP"); return ADDOP;}
"-"		{yylval = Symbolinfo(yytext, "SUBOP"); return SUBOP;}
"*"		{yylval = Symbolinfo(yytext, "MULOP");return MULOP;}
"/"		{yylval = Symbolinfo(yytext, "DIVOP"); return DIVOP;}
"%"		{yylval = Symbolinfo(yytext, "MODOP"); return MODOP;}
"="		{yylval = Symbolinfo(yytext, "ASSOP"); return ASSOP;}
"("		{yylval = Symbolinfo(yytext, "LPAREN"); return LPAREN;}
")"		{yylval = Symbolinfo(yytext, "RPAREN"); return RPAREN;}
"{"		{yylval = Symbolinfo(yytext, "LCURL"); return LCURL;}
"}"		{yylval = Symbolinfo(yytext, "RCURL"); return RCURL;}

%%

