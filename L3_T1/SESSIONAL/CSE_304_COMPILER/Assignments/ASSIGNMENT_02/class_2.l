%option noyywrap
%{
#include<stdio.h>
#include "cls1.h"
Symboltable Table; 
int line=1; 
FILE *yylog;
%}


ws              [ \t]+
digit           [0-9]
letter          [A-Za-z]
integer         {digit}+
floatpart       {digit}*\.{digit}+
exppart         ({intNumber}|{floatpart})[Ee][+-]?{digit}+
floating         [0-9]*\.[0-9]+([eE][-+]?[0-9]+)?
char            '.'
id              ({letter}|_)({letter}|{digit}|_)*

Expoerror       {digit}+[Ee]{digit}+\.{digit}+
Decimalerror    {digit}*\.{digit}+\.[^ \t\n]*
unfinished_char  '[.\n]
unfinished_str   \".*\n 
multi_char       '[^{ws}][^']+'

%%

{ws} {}
\n  {line++;}
if {fprintf(yylog,"Line No: %d Token <IF> Lexeme if found\n",line); fprintf(yyout,"<IF>");}
else {fprintf(yylog,"Line No: %d Token <ELSE> Lexeme else found\n",line); fprintf(yyout,"<ELSE>");}
for {fprintf(yylog,"Line No: %d Token <FOR> Lexeme for found\n",line); fprintf(yyout,"<FOR>");}
while {fprintf(yylog,"Line No: %d Token <ELSE> Lexeme while found\n",line); fprintf(yyout,"<WHILE>");}
do {fprintf(yylog,"Line No: %d Token <ELSE> Lexeme do found\n",line); fprintf(yyout,"<DO>");}
break {fprintf(yylog,"Line No: %d Token <BREAK> Lexeme break found\n",line); fprintf(yyout,"<BREAK>");}
int {fprintf(yylog,"Line No: %d Token <INT> Lexeme int found\n",line); fprintf(yyout,"<INT>");}
char {fprintf(yylog,"Line No: %d Token <CHAR> Lexeme char found\n",line); fprintf(yyout,"<CHAR>");}
float {fprintf(yylog,"Line No: %d Token <FLOAT> Lexeme float found\n",line); fprintf(yyout,"<FLOAT>");}
double {fprintf(yylog,"Line No: %d Token <DOUBLE> Lexeme double found\n",line); fprintf(yyout,"<DOUBLE>");}
void {fprintf(yylog,"Line No: %d Token <VOID> Lexeme void found\n",line); fprintf(yyout,"<VOID>");}
return {fprintf(yylog,"Line No: %d Token <RETURN> Lexeme return found\n",line); fprintf(yyout,"<RETURN>");}
switch {fprintf(yylog,"Line No: %d Token <SWITCH> Lexeme switch found\n",line); fprintf(yyout,"<SWITCH>");}
case {fprintf(yylog,"Line No: %d Token <CASE> Lexeme case found\n",line); fprintf(yyout,"<CASE>");}
default {fprintf(yylog,"Line No: %d Token <DEFAULT> Lexeme default found\n",line); fprintf(yyout,"<DEFAULT>");}
continue {fprintf(yylog,"Line No: %d Token <CONTINUE> Lexeme continue found\n",line); fprintf(yyout,"<CONTINUE>");}

{id} {fprintf(yylog,"Line No: %d Token <ID> Lexeme %s found\n",line, yytext); fprintf(yyout, "<ID, %s>", yytext); Symbolinfo Info(yytext,"ID") ;Table.insert(Info);}

{integer} {fprintf(yylog,"Line No: %d Token <CONST_INT> Lexeme %s found\n",line, yytext); fprintf(yyout, "<CONST_INT, %s>", yytext); Symbolinfo Info(yytext, "CONST_INT") ;Table.insert(Info);}

{floating} {fprintf(yylog, "Line No: %d Token <CONST_FLOAT> Lexeme %s found\n", line, yytext); fprintf(yyout, "<CONST_FLOAT, %s>", yytext); Symbolinfo Info(yytext, "CONST_FLOAT"); Table.insert(Info);}

{char} {fprintf(yylog,"Line No: %d Token <CONST_CHAR> Lexeme %s found\n",line, yytext); fprintf(yyout, "<CONST_CHAR, %s>", yytext); Symbolinfo Info(yytext, "CONST_CHAR") ;Table.insert(Info);}

"+"|"-" {fprintf(yylog,"Line No: %d Token <ADDOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<ADDOP, %s>",yytext);}
"*"|"/"|"%" {fprintf(yylog,"Line No: %d Token <MULOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<MULOP, %s>",yytext);}
"++"|"--" {fprintf(yylog,"Line No: %d Token <INCOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<INCOP, %s>",yytext);}
"=="|"!="|"<"|">"|"<="|">=" {fprintf(yylog,"Line No: %d Token <RELOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<RELOP, %s>",yytext);}
"=" {fprintf(yylog,"Line No: %d Token <ASSOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<ASSOP, %s>",yytext);}
"&&"|"||" {fprintf(yylog,"Line No: %d Token <LOGICOP> Lexeme %s found\n",line,yytext);fprintf(yyout,"<LOGICOP, %s>",yytext);}
"!" {fprintf(yylog,"Line No: %d Token <NOT> Lexeme %s found\n",line,yytext);fprintf(yyout,"<NOT, %s>",yytext);}
"(" {fprintf(yylog,"Line No: %d Token <LPAREN> Lexeme %s found\n",line,yytext);fprintf(yyout,"<LPAREN, %s>",yytext);}
")" {fprintf(yylog,"Line No: %d Token <RPAREN> Lexeme %s found\n",line,yytext);fprintf(yyout,"<RPAREN, %s>",yytext);}
"{" {fprintf(yylog,"Line No: %d Token <LCURL> Lexeme %s found\n",line,yytext);fprintf(yyout,"<LCURL, %s>",yytext);}
"}" {fprintf(yylog,"Line No: %d Token <RCURL> Lexeme %s found\n",line,yytext);fprintf(yyout,"<RCURL, %s>",yytext);}
"[" {fprintf(yylog,"Line No: %d Token <L3RD> Lexeme %s found\n",line,yytext);fprintf(yyout,"<L3RD, %s>",yytext);}
"]" {fprintf(yylog,"Line No: %d Token <R3RD> Lexeme %s found\n",line,yytext);fprintf(yyout,"<R3RD, %s>",yytext);}
";" {fprintf(yylog,"Line No: %d Token <SEMICOLON> Lexeme %s found\n",line,yytext);fprintf(yyout,"<SEMICOLON, %s>",yytext);}
"," {fprintf(yylog,"Line No: %d Token <COMMA> Lexeme %s found\n",line,yytext);fprintf(yyout,"<COMMA, %s>",yytext);}

\".*"\  {fprintf(yyout,"<SSTRING, %s>",yytext);}
"//".* 	{fprintf(yyout,"<Single_Comment, %s>",yytext);}
"/*"(.|\n|//)*"*/"  {fprintf(yyout,"<Multi_Comment, %s>",yytext);}



{Expoerror} {fprintf(yylog, "Error at Line No: %d Ill formated number %s\n", line, yytext);}
{Decimalerror} {fprintf(yylog, "Error at Line No: %d Ill formated number %s\n", line, yytext);}
{unfinished_char} {fprintf(yylog, "Error at Line No: %d Unfinished character %s\n", line, yytext);}
{unfinished_str} {fprintf(yylog,"ERROR at Line No: %d Unfinished String %s\n",line,yytext);}
{multi_char} {fprintf(yylog, "Error at Line No: %d Multi character constant error %s\n", line, yytext);}
. {fprintf(yylog, "Error at Line No: %d Unauthorized Character %s\n", line, yytext);}

%%

int main(){
	yyin = fopen("i.txt","r");
	yyout = fopen("o.txt","w");
	yylog = freopen("l.txt", "w", stdout);
	yylex();
	return 0;	
}

