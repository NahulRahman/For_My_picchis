%{
	#include<bits/stdc++.h>
	#include<fstream>
	using namespace std;
	extern FILE* yyin;
	extern char* token_name;
	extern double num;
 #include "test_final.h"
  // #define YYSTYPE Symbol_info
	extern ofstream LOG_ERROR;

	int line_number=1;
	int yylex(void);

	void yyerror(const char *s) 
	{
		LOG_ERROR<<string(s)<<endl;	
	}
%}

%token ID INT CONST_INT FLOAT DOUBLE NEWLINE SEMICOLON 
%left LPAREN RPAREN 
%left LTHIRD RTHIRD 
%left MULOP DIVOP MODOP 
%left ADDOP SUBOP 
%left LOGICOP 
%right ASSIGNOP 
%left COMMA

%%

stmt: stmt unit							    {
												LOG_ERROR<<endl<<endl;
											    line_number++;
											} 

| unit										{
												LOG_ERROR<<endl<<endl;
												line_number++;
											} 
;

unit: var_decl NEWLINE                      {
												
											}

| expr_decl NEWLINE                         {
												

											}
| func_decl NEWLINE							{


											}

|error NEWLINE                              {
												//yyerrorok();
											}	
;

func_decl: type_spec term LPAREN param_decl RPAREN SEMICOLON {
	
	                                        LOG_ERROR<<"Line Number: "<<line_number<<endl<<"func_decl: type_spec term LPAREN param_decl RPAREN SEMICOLON"<<endl;
											
											}

;

var_decl: type_spec decl_list SEMICOLON 	{
	                                            LOG_ERROR<<"Line Number: "<<line_number<<endl<<"var_decl: type_spec decl_list SEMICOLON"<<endl;
											}
;

///

param_decl: type_spec term  COMMA param_decl       {
	                                            LOG_ERROR<<"Line Number: "<<line_number<<endl<<"param_decl: type_spec term COMMA param_decl	"<<endl;
											}
| type_spec term 							{
	                                            LOG_ERROR<<"Line Number: "<<line_number<<endl<<"param_decl: type_spec term"<<endl;
											}
;


///
type_spec: INT 								{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"type_spec: INT"<<endl;
											
											}

| FLOAT 								    {
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"type_spec: FLOAT"<<endl;
												
											}

| DOUBLE 								    {
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"type_spec: DOUBLE"<<endl;
											}
;

decl_list: decl_list COMMA term 			{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list: decl_list COMMA term"<<endl;
												
											}

| decl_list COMMA term LTHIRD CONST_INT RTHIRD 	{
	 											double num_type = num;
	                                        	int a = floor(num_type);
												int b = ceil(num_type);

												if(a==b) 
												{
													LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list COMMA term LTHIRD CONST_INT RTHIRD"<<endl;
												
												}
												else
													yyerror("Syntax error");
											}

| term 										{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list: term"<<endl;
											
											}

| term LTHIRD CONST_INT RTHIRD 				{
	                                            double num_type = num;
	                                            int a = floor(num_type);
												int b = ceil(num_type);

												if(a==b) 
												{
													LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list: term LTHIRD CONST_INT RTHIRD"<<endl;
													
												}
												else
													yyerror("Syntax error");
											}

|ass_list 									{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list: ass_list"<<endl;
												
											}
;

ass_list: term ASSIGNOP expr 				{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"decl_list: term ASSOP expr"<<endl;
											
											}
;

expr: CONST_INT 			                {
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: CONST_INT"<<endl;
									
											}
											
| LPAREN expr RPAREN 						{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: LPAREN expr RPAREN"<<endl;
									
											}

| expr MULOP expr    						{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr MULOP expr"<<endl;
									
											}

| expr DIVOP expr                           {
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr DIVOP expr"<<endl;
										    } 

| expr MODOP expr    						{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr MODOP expr"<<endl;									
											} 

| expr ADDOP expr     						{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr ADDOP expr"<<endl;									

											}

| expr SUBOP expr 	 						{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr SUBOP expr"<<endl;									

											}			   

| expr LOGICOP expr  	 					{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: expr LOGICOP expr"<<endl;									

											}
					                      
| term 				                        {
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr: term"<<endl;

	                                        }
;

term: ID 									{
												//Symbol_info SI("identifier",token_name);
												// if(ST.Insert(&SI))
												// {
												// 	LOG_ERROR<<"Line Number: "<<line_number<<endl<<"term: ID"<<endl;
												// }
												// else
												// {
											    // 	LOG_ERROR<<token_name<<" is already declared."<<endl;
												// } 
											}
;

expr_decl: term ASSIGNOP expr SEMICOLON 	{
												LOG_ERROR<<"Line Number: "<<line_number<<endl<<"expr_decl: term ASSIGNOP expr SEMICOLON"<<endl;

											}
;

%%



int main()
{
	yyin = fopen("input.txt","r");
	LOG_ERROR.open("log.txt",std::ofstream::out | std::ofstream::app);
	LOG_ERROR<<"hello"<<endl;
	yyparse();
	fclose(yyin);
	LOG_ERROR.close();
	//LOGG.close();
	//ST.Print();
	return 0;
}