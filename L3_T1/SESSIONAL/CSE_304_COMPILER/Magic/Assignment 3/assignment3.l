%option noyywrap

%{

#include<bits/stdc++.h>
using namespace std;
#include "test_final.h"
int count=0;
int line_no=1;
FILE *outlog,*output;
SymbolTable T;
%}

ws              [ \t]+
digit           [0-9]
letter          [A-Za-z]
intNumber       {digit}+
floatpart       {digit}*\.{digit}+
exppart         ({intNumber}|{floatpart})[Ee][+-]?{digit}+
floatNumber     {floatpart}|{exppart}
char            '.'
ID              ({letter}|_)({letter}|{digit}|_)*
ExpError        {digit}+[Ee]{digit}+\.{digit}+
DecimalError    {digit}*\.{digit}+\.[^ \t\n]*

%%

{ws}                {}
\n                  {line_no++;}
if                  {fprintf(outlog,"Line No: %d Token <IF> Lexeme if found\n",line_no); fprintf(output,"<IF>");}
else                {fprintf(outlog,"Line No: %d Token <ELSE> Lexeme else found\n",line_no);fprintf(output,"<ELSE>");}
for                 {fprintf(outlog,"Line No: %d Token <FOR> Lexeme for found\n",line_no); fprintf(output,"<FOR>");}
while               {fprintf(outlog,"Line No: %d Token <WHILE> Lexeme while found\n",line_no);fprintf(output,"<WHILE>");}
do                  {fprintf(outlog,"Line No: %d Token <DO> Lexeme do found\n",line_no);fprintf(output,"<DO>");}
break               {fprintf(outlog,"Line No: %d Token <BREAK> Lexeme break found\n",line_no);fprintf(output,"<BREAK>");}
int                 {fprintf(outlog,"Line No: %d Token <INT> Lexeme int found\n",line_no);fprintf(output,"<INT>");}
char                {fprintf(outlog,"Line No: %d Token <CHAR> Lexeme char found\n",line_no);fprintf(output,"<CHAR>");}
float               {fprintf(outlog,"Line No: %d Token <FLOAT> Lexeme float found\n",line_no);fprintf(output,"<FLOAT>");}
double              {fprintf(outlog,"Line No: %d Token <DOUBLE> Lexeme double found\n",line_no);fprintf(output,"<DOUBLE>");}
void                {fprintf(outlog,"Line NO: %d Token <VOID> Lexeme void found\n",line_no);fprintf(output,"<VOID>");}
return              {fprintf(outlog,"Line No: %d Token <RETURN> Lexeme return found\n",line_no);fprintf(output,"<RETURN>");}
switch              {fprintf(outlog,"Line No: %d Token <SWITCH> Lexeme switch found\n",line_no);fprintf(output,"<SWITCH>");}
case                {fprintf(outlog,"Line No: %d Token <CASE> Lexeme case found\n",line_no); fprintf(output,"<CASE>");}
default             {fprintf(outlog,"Line No: %d Token <DEFAULT> Lexeme default found\n",line_no);fprintf(output,"<DEFAULT>");}
continue            {fprintf(outlog,"Line No: %d Token <CONTINUE> Lexeme continue found\n",line_no);fprintf(output,"<CONTINUE>");}
                    
{ID}                {fprintf(outlog,"Line No: %d Token <ID> Lexeme %s found\n",line_no,yytext);
                     fprintf(output,"<ID, %s>",yytext);
                     SymbolInfo obj=SymbolInfo(yytext,"ID");
                     T.insert(outlog,obj);
                    }
{intNumber}         {fprintf(outlog,"Line No: %d Token <CONST_INT> Lexeme %s found\n",line_no,yytext);
                     fprintf(output,"<CONST_INT, %s>",yytext);
                     SymbolInfo obj=SymbolInfo(yytext,"CONST_INT");
                     T.insert(outlog,obj);
                    }
{floatNumber}       {fprintf(outlog,"Line No: %d Token <CONST_FLOAT> Lexeme %s found\n",line_no,yytext);
                    fprintf(output,"<CONST_FLOAT, %s>",yytext);
                    SymbolInfo obj=SymbolInfo(yytext,"CONST_FLOAT");
                    T.insert(outlog,obj);}                     
{char}              {fprintf(outlog,"Line No: %d Token <CONST_CHAR> Lexeme %s found\n",line_no,yytext);
                    fprintf(output,"<CONST_CHAR, %s>",yytext);
                    SymbolInfo obj=SymbolInfo(yytext,"CONST_CHAR");
                    T.insert(outlog,obj);}

 (\+|-)              {fprintf(outlog,"Line No: %d Token <ADDOP> Lexeme %s found\n",line_no,yytext);fprintf(output,"<ADDOP, %s>",yytext);}
(\*|\/|%)           {fprintf(outlog,"Line No: %d Token <MULOP> Lexeme %s found\n",line_no,yytext);fprintf(output,"<MULOP, %s>",yytext);}
(\+\+|--)           {fprintf(outlog,"Line No: %d Token <INCOP> Lexeme %s found\n",line_no,yytext);fprintf(output,"<INCOP, %s>",yytext);}
(<|<=|>|>=|==|!=)   {fprintf(outlog,"Line No: %d Token <RELOP> Lexeme %s found\n",line_no,yytext); fprintf(output,"<RELOP, %s>",yytext);}
=                   {fprintf(outlog,"Line No: %d Token <ASSIGNOP> Lexeme %s found\n",line_no,yytext); fprintf(output,"<ASSIGNOP, %s>",yytext);}
(&&|\|\|)           {fprintf(outlog,"Line No: %d Token <LOGICOP> Lexeme %s found\n",line_no,yytext);fprintf(output,"<LOGICOP, %s>",yytext);}
!                   {fprintf(outlog,"Line No: %d Token <NOT> Lexeme %s found\n",line_no,yytext);fprintf(output,"<NOT, %s>",yytext);}
\(                  {fprintf(outlog,"Line No: %d Token <LPAREN> Lexeme %s found\n",line_no,yytext); fprintf(output,"<LPAREN, %s>",yytext);}
\)                  {fprintf(outlog,"Line No: %d Token <RPAREN> Lexeme %s found\n",line_no,yytext);fprintf(output,"<RPAREN, %s>",yytext);}
\{                  {fprintf(outlog,"Line No: %d Token <LCURL> Lexeme %s found\n",line_no,yytext);fprintf(output,"<LCURL, %s>",yytext);}
\}                  {fprintf(outlog,"Line No: %d Token <RCURL> Lexeme %s found\n",line_no,yytext);fprintf(output,"<RCURL, %s>",yytext);} 
\[                  {fprintf(outlog,"Line No: %d Token <LTHIRD> Lexeme %s found\n",line_no,yytext); fprintf(output,"<LTHIRD, %s>",yytext);}
\]                  {fprintf(outlog,"Line No: %d Token <RTHIRD> Lexeme %s found\n",line_no,yytext);fprintf(output,"<RTHIRD, %s>",yytext);}
,                   {fprintf(outlog,"Line No: %d Token <COMMA> Lexeme %s found\n",line_no,yytext);fprintf(output,"<COMMA, %s>",yytext);}
;                   {fprintf(outlog,"Line No: %d Token <SEMICOLON> Lexeme %s found\n",line_no,yytext);fprintf(output,"<SEMICOLON, %s>",yytext);}


{ExpError}           {fprintf(outlog,"ERROR at Line No: %d Invalid Number %s\n",line_no,yytext);}                     
{DecimalError}      {fprintf(outlog,"ERROR at Line No: %d Too many decimal points %s\n",line_no,yytext);}
\".*\n              {fprintf(outlog,"ERROR at Line No: %d Unfinished String %s\n",line_no,yytext);}
 '[.\n]             {fprintf(outlog,"ERROR at Line No: %d Unfinished character %s\n",line_no,yytext);}
 \"[^"\n]+\"|\"[^"\n]+(\\\n[^"\n]+)+\"        {fprintf(outlog,"String at Line No: %d String found %s\n",line_no,yytext);}


.                   {fprintf(outlog,"ERROR at Line No: %d LEXICAL ERROR %s\n",line_no,yytext);}
%%

int main()
{

//printf("line num: %d",line_no);
  
    yyin= fopen("input.txt","r");
    outlog = fopen("202014017_log.txt","w");
    output = fopen("202014017_token.txt","w");
    yylex();
    fclose(yyin);
    fclose(outlog);
    fclose(output);
    return 0;
}
