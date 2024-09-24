%option noyywrap
%{
#include<stdio.h>
#include <stdlib.h>
#include "cls1.h"
Symboltable uable;
#include "d.tab.h"
extern int line;

%}

letter          		[A-Za-z]
integer				[0-9]+
floating			[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?
id              		({letter}|_)({letter}|{integer}|_)*

%%

"int"           		{return INT;}
"float"         		{return FLOAT;}
"double"        		{return DOUBLE;}

{integer}     			{return CONST_INT;}
{floating}   			{return CONST_FLOAT;}
{id}    			{bool flag = uable.insert(Symbolinfo(yytext, "ID"));
				if(flag==false)
{
	
 fprintf(yyout, "%s is already declared\n", yytext); 
}
 return ID;}

","				{return COMMA;}
";"				{return SEMICOLON;}
"+"				{return ADDOP;}
"-"				{return MINUS;}
"*"				{return MULOP;}
"/"				{return DIVOP;}
"%"				{return MODOP;}
"="				{return ASSOP;}
"<"|"<="|">"|">="|"=="|"!=" 	{return RELOP;}
"&&"|"||"			{return LOGICOP;}
"++"|"--"			{return INCR;}
"("				{return LPAREN;}
")"				{return RPAREN;}
"{"				{return LCURL;}
"}"				{return RCURL;}
"["				{return LTHIRD;}
"]"				{return RTHIRD;}
"\n"              		{line++;}
[ \t]+          		{}
.               		{}
%%