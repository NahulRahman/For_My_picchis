%{
	#include<bits/stdc++.h>
	using namespace std;
	extern FILE* yyin;
	extern char* token_name;
	extern double num;
	#include "test_final.h"

	extern ofstream LOG_ERROR;

	int line_no=1;
	int yylex(void);

	void yyerror(const char *s) 
	{
		LOG_ERROR<<string(s)<<endl;	
	}
%}

%token ID INT DOUBLE  CONST_INT FLOAT SEMICOLON NEWLINE
 
%left COMMA 
%left LTHIRD 
%left RTHIRD 
%right ASSOP 
%left MULOP 
%left DIVOP 
%left MODOP 
%left MINUS 
%left PLUS 
%left GRTTHAN 
%left LESSTHAN 
%left LAND 
%left LOR 
%left LPARAN 
%left RPARAN
%left  RCURL 
%left  LCURL

%%

stmt: stmt unit							    {
												LOG_ERROR<<endl<<endl;
											    line_nO++;
											} 

| unit										{
												LOG_ERROR<<endl<<endl;
												line_nO++;
											} 
;

unit: var_decl NEWLINE                      {
												
											}

| expr_decl NEWLINE                         {
												

											}
|  NEWLINE							{


											}

|error NEWLINE                              {
												
											}	
;

func_decl: type_spec term LPAREN parameter_decl RPAREN SEMICOLON {
	func_decl
	                                        LOG_ERROR<<"Line Number: "<<line_no<<endl<<"func_decl: type_spec term LPAREN parameter_decl RPAREN SEMICOLON"<<endl;
											
											}

;

var_decl: type_spec decl_list SEMICOLON 	{
	                                            LOG_ERROR<<"Line Number: "<<line_no<<endl<<"var_decl: type_spec decl_list SEMICOLON"<<endl;
											}
;


parameter_decl: type_spec term  COMMA parameter_decl       {
	                                            LOG_ERROR<<"Line Number: "<<line_no<<endl<<"parameter_decl: type_spec term COMMA parameter_decl	"<<endl;
											}
| type_spec term 							{
	                                            LOG_ERROR<<"Line Number: "<<line_no<<endl<<"parameter_decl: type_spec term"<<endl;
											}
;



type_spec: INT 								{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"type_spec: INT"<<endl;
											
											}

| FLOAT 								    {
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"type_spec: FLOAT"<<endl;
												
											}

| DOUBLE 								    {
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"type_spec: DOUBLE"<<endl;
											}
;

decl_list: decl_list COMMA term 			{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list: decl_list COMMA term"<<endl;
												
											}

| decl_list COMMA term LTHIRD CONST_INT RTHIRD 	{
	 											double num_type = num;
	                                        	int a = floor(num_type);
												int b = ceil(num_type);

												if(a==b) 
												{
													LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list COMMA term LTHIRD CONST_INT RTHIRD"<<endl;
												
												}
												else
													yyerror("Syntax error");
											}

| term 										{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list: term"<<endl;
											
											}

| term LTHIRD CONST_INT RTHIRD 				{
	                                            double num_type = num;
	                                            int a = floor(num_type);
												int b = ceil(num_type);

												if(a==b) 
												{
													LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list: term LTHIRD CONST_INT RTHIRD"<<endl;
													
												}
												else
													yyerror("Syntax error");
											}

|ass_list 									{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list: ass_list"<<endl;
												
											}
;

ass_list: term ASSIGNOP expr 				{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"decl_list: term ASSOP expr"<<endl;
											
											}
;

expr: CONST_INT 			                {
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: CONST_INT"<<endl;
									
											}
											
| LPAREN expr RPAREN 						{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: LPAREN expr RPAREN"<<endl;
									
											}

| expr MULOP expr    						{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr MULOP expr"<<endl;
									
											}

| expr DIVOP expr                           {
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr DIVOP expr"<<endl;
										    } 

| expr MODOP expr    						{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr MODOP expr"<<endl;									
											} 

| expr ADDOP expr     						{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr ADDOP expr"<<endl;									

											}

| expr SUBOP expr 	 						{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr SUBOP expr"<<endl;									

											}			   

| expr LOGICOP expr  	 					{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: expr LOGICOP expr"<<endl;									

											}
					                      
| term 				                        {
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr: term"<<endl;

	                                        }
;

term: ID 									{
												SymbolInfo ob("identifier",token_name);
												 if(ob.insert(&ob))
												 {
												 	LOG_ERROR<<"Line Number: "<<line_no<<endl<<"term: ID"<<endl;
												 }
												 else
												 {
											    	LOG_ERROR<<token_name<<" Token is already declared."<<endl;
												 } 
											}
;

expr_decl: term ASSIGNOP expr SEMICOLON 	{
												LOG_ERROR<<"Line Number: "<<line_no<<endl<<"expr_decl: term ASSIGNOP expr SEMICOLON"<<endl;

											}
;

%%



int main()
{
	yyin = fopen("sample_input.txt","r");
	yyparse();
	fclose(yyin);
	LOG_ERROR.close();
	
	return 0;
}