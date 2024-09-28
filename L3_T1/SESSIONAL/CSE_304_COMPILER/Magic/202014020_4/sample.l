%option noyywrap
%{
#include<cstdio>
#include<stdio.h>
#include<fstream>   
#include <bits/stdc++.h>
#include "symbolTable.h"
#include "yacc.tab.h"
symboltable ob;

%}
letter		[A-Za-z]
var 		(({letter}|_)({letter}|{digit}|_)*)
digit		[0-9]
digits		{digit}+
number 		{digits}(\.{digits})?(E[+-]?{digits})?

%%
int			{return INT;}
{var}		{ob.insert(yytext,"Identifier");ob.print(); return ID;}
{number}	{return NUM;}
";"			{return SEMICOLON;}
","			{return COMMA;}
"["			{return LTHIRD;}
"]"			{return RTHIRD;}
"="			{return ASSOP;}
"*"			{return MULOP;}
"/"			{return DIVOP;}
"%"			{return MODOP;}
"-"			{return MINUS;}
"+"			{return PLUS;}
">"			{return GRTTHAN;}
"<"			{return LESSTHAN;}
"&&"		{return LAND;}
"||"		{return LOR;}
"("			{return LPARAN;}
")"			{return RPARAN;}
"\n"		{return NEWLINE;}

%%
