%option noyywrap
%{
#include<bits/stdc++.h>
using namespace std;
char* token_name;
double num;
ofstream LOG("log.txt");
ofstream LOG_ERROR("log_error.txt");
#include"assignment4.tab.h"

%}
Keyword   if|while|do|break|void|return|switch|case
letter		[A-Za-z]
var 		(({letter}|_)({letter}|{digit}|_)*)
digit		[0-9]
intNumber   {digit}+
floatpart       {digit}*\.{digit}+
floatNumber     {floatpart}|{exppart}
exppart         ({intNumber}|{floatpart})[Ee][+-]?{digit}+


%%

{Keyword}    {}
exit 		 {exit(0);}
int			{return INT;}
double      {return DOUBLE;}
{var}		{token_name=yytext; 
               return ID;;}
{intNumber}	 {char* p=yytext;
			  string s=string(p);
			  num = stod(s);
	          return CONST_INT;;}
{floatNumber}  {return FLOAT;}

";"			{return SEMICOLON;}
","			{return COMMA;}
"["			{return LTHIRD;}
"]"			{return RTHIRD;}
"="			{return ASSIGNOP;}
"*"			{return MULOP;}
"/"			{return DIVOP;}
"%"			{return MODOP;}
"-"			{return SUBOP;}
"+"			{return ADDOP;}
">"			{return GRTTHAN;}
"<"			{return LESSTHAN;}
\&\&|\|\|	 {return LOGICOP;}
"("			{return LPARAN;}
")"			{return RPARAN;}
"{"         {return LCURL; }

"}"         { return RCURL; }

"\n"		{return NEWLINE;}


%%
