%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "node.h"
int yylex();
int yyerror( char *msg );
extern int line_no;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */
%}
%union{
	int int_val;
	double real_val;
	char *string;
	struct node *node;
}

%token <string> id
%token <string> PROGRAM PROCEDURE ARRAY VAR OF FUNCTION
%token <string> INTEGER REAL STRING DOTDOT RBRAC LBRAC
%token <string> IF THEN ELSE WHILE DO PBEGIN END NOT ASSIGNMENT COLON SEMICOLON LPAREN RPAREN DOT COMMA
%token <string> PLUS MINUS STAR SLASH GT EQUAL LE GE notEQUAL LT
%token <int_val> CONST_INT
%token <real_val> CONST_REAL
%token <string> CONST_STRING
%type  <node> NUM
%type  <node> prog identifier_list declarations type standard_type subprogram_declarations subprogram_declaration subprogram_head arguments parameter_list optional_var compound_statement optional_statements statement_list statement variable tail procedure_statement expression_list expression simple_expression term factor addop mulop relop lambda

%%
prog    :  
		PROGRAM
		id
		LPAREN
		identifier_list 
		RPAREN
		SEMICOLON
		declarations 
		subprogram_declarations 
		compound_statement 
		DOT{
			$$ = newNode(NODE_prog);
			struct node *temp = newNode(K_id);
			temp->string = strdup($2);
			addChild($$,temp);//first child of "prog" is the name of program
			addChild($$,$4);//second one is the parameter passed in the program
			addChild($$,$7);//3rd child is declarations of global variable
			addChild($$,$8);//4th child is declarations of subprogram
			addChild($$,$9);//compound_statement: the variable in it may need classifying
			printf("reduce prog->PROGRAM PROGRAM id ( identifier_list ) ; declarations subprogram_declarations compound_statement .\n");
			semanticCheck($$);
		}
		;


identifier_list : 
	id{
		printf("reduce identifier_list->id\n");
		$$ = newNode(NODE_identifier_list);
		struct node *temp = newNode(K_id);
		temp->string = strdup($1);
		addChild($$,temp);
	}
	| identifier_list 
	COMMA
	id{
		struct node *temp = newNode(K_id);
		temp->string = strdup($3);
		addChild($1,temp);
		$$ = $1;
		printf("reduce identifier_list-> identifier_list , id\n");
	}
	;

declarations : 
	declarations 
	VAR
	identifier_list 
	COLON
	type 
	SEMICOLON{//there are bugs here
		struct node *temp = newNode(NODE_declaration);//a "declaration" contains id_list and type,while "declarations" is  the parent of sets of declaration
		addChild(temp,$3);//the first child of declaration is its id_list
		addChild(temp,$5);//second one is its type
		if($1!=NULL){
			addChild($1,temp);				
			$$ = $1;                        
		}                                   
		else{
			$$ = newNode(NODE_declarations);
			addChild($$,temp);
		}
			
		printf("reduce declarations->declarations VAR identifier_list , type ;\n");
	}
	| lambda{
		$$ = newNode(NODE_declarations);//this is declarataion with NULL child
		printf("reduce declarations->lambda\n");
	}
	;

type : standard_type{
		$$ = newNode(NODE_type);
		switch($1->nodeType){
			case K_INTEGER:
				$$->tokenType = K_INTEGER;
			break;
			case K_REAL:
				$$->tokenType = K_REAL;
			break;
			case K_STRING:
				$$->tokenType = K_STRING;
			break;
		}
		$$->arraydepth=0;
		$$->ref = NULL;
		$$->idxstart = 0;
		$$->idxend   = 0;
		printf("reduce type->standard_type\n");
	}
	| ARRAY
	LBRAC
	NUM
	DOTDOT
	NUM
	RBRAC
	OF
	type{
		$$ = newNode(NODE_type);
		$$->tokenType = $8->tokenType;
		$$->arraydepth= $8->arraydepth + 1;
		$$->idxstart = $3;
		$$->idxend = $5;
		$$->ref = $8;
		printf("reduce type->array [ num .. num ] of type \n");
	}
	;


standard_type : 
	INTEGER{
		$$ = newNode(K_INTEGER);
		printf("reduce standard_type->integer\n");
	}
	| REAL{
		$$ = newNode(K_REAL);
		printf("reduce standard_type->real\n");
	}
    | STRING{
		$$ = newNode(K_STRING);
		printf("reduce standard_type->string\n");
	}
	;

subprogram_declarations :
	subprogram_declarations 
	subprogram_declaration 
	SEMICOLON{
		if($1 == NULL){
			$$ = newNode(NODE_subprogram_declarations);
			addChild($$,$2);
		}
		else{
			addChild($1,$2);
			$$ = $1;
		}
		printf("reduce subprogram_declarations->subprogram_declarations subprogram_declaration ;\n");
	}
	| lambda{
		$$ = newNode(NODE_subprogram_declarations);
		printf("reduce subprogram_declarations->lamda\n");
	}
	;

subprogram_declaration :
	subprogram_head
	declarations 
	compound_statement{
		$$ = newNode(NODE_subprogram_declaration);
		addChild($$,$1);//the first child is subprogram_head;
		addChild($$,$2);//second one is declaration
		addChild($$,$3);//third one is compound_statement, need to verify the semantics
		printf("reduce subprogram_declaration->subprogram_head declarations compound_statement\n");
	}
	;
subprogram_head : 
	FUNCTION
	id
	arguments
	COLON
	standard_type 
	SEMICOLON{
		$$ = newNode(NODE_subprogram_head);
		struct node *temp = newNode(K_id),*temp2 = newNode(NODE_type);
		temp2->tokenType = $5->nodeType;
		temp2->arraydepth=0;
		temp2->ref = NULL;
		temp2->idxstart = 0;
		temp2->idxend   = 0;
		temp->string = strdup($2);
		addChild($$,temp);//first child is name of subprogram
		addChild($$,$3);//second child is arguments
		addChild($$,temp2);//third one is type of subprogram
		printf("reduce subprogram_head->FUNCTION id arguments : standard_type ; \n");
	}
	| PROCEDURE
	id
	arguments
	SEMICOLON{
		$$ = newNode(NODE_subprogram_head);
		struct node *temp = newNode(K_id);
		temp->string = strdup($2);
		addChild($$,temp);//first child is name of subprogram
		addChild($$,$3);//third child is arguments
		struct node *null_type = newNode(VALUE_INVALID);//should not be any type here!
		printf("reduce subprogram_head->PROCEDURE id arguments;\n");
	}
	;


arguments : 
	LPAREN
	parameter_list 
	RPAREN{
		$$ = newNode(NODE_arguments);
		addChild($$,$2);//first child is parameter_list
		printf("reduce arguments->( parameter_list ) \n");
	}
	| lambda{
		$$ = newNode(NODE_arguments);
		printf("reduce arguments->lambda\n");
	}
	;

parameter_list : 
	optional_var 
	identifier_list 
	COLON
	type{
		struct node *temp = newNode(NODE_parameter_list_single);
		addChild(temp,$2);//the first child of single list is id_list
		addChild(temp,$4);//the second one is type
		$$ = newNode(NODE_parameter_list);//parameter_list holds sets of single parameter_list
		addChild($$,temp);
		printf("reduce parameter_list->optional_var identifier_list : type\n");
	}
	| optional_var
	identifier_list
	COLON
	type
	SEMICOLON
	parameter_list{
		struct node *temp = newNode(NODE_parameter_list_single);
		addChild(temp,$2);
		addChild(temp,$4);
		if($6!=NULL){
			addChild($6,temp);
			$$ = $6;
		}
		else{
			$$ = newNode(NODE_parameter_list);
			addChild($$,temp);
		}
		printf("reduce parameter_list->optional_var identifier : type ; parameter_list\n");
	} 
	;

optional_var   : 
	VAR{
		printf("reduce optional_var->VAR\n");
	}
    | lambda{
		printf("reduce optional_val->lambda\n");
	}
	;

compound_statement : 
	PBEGIN
	optional_statements 
	END{
		$$ = newNode(NODE_compound_statement);
		addChild($$,$2);
		printf("reduce compound_statement->BEGIN optional_statements END\n");
	}
	;

optional_statements : 
	statement_list{
		$$ = $1;//the content of optional_statements is just list of statement
		printf("reduce optional_statements->statement_list\n");
	}
	| lambda{
		$$ = newNode(NODE_statement_list);//statement list with no content
		printf("reduce optional_statements->lambda\n");
	}
	;


statement_list : 
	statement{
		$$ = newNode(NODE_statement_list);
		addChild($$,$1);
		printf("reduce statement_list->statement\n");
	}
	| statement_list
	SEMICOLON
	statement{
		addChild($1,$3);//the child of statement list is statement
		$$ = $1;
		printf("reduce statement_list->statement';'statement\n");
	}
	;

statement : 
	variable 
	ASSIGNMENT
	expression{
		$$ = newNode(NODE_statement);
		addChild($$,$1);//first child of statement is variable to be assigned
		addChild($$,$3);//second one is expression
		printf("reduce statement->variable := expression\n");
	}
	| procedure_statement{
		$$ = $1;
		printf("reduce statement->procedure_statement\n");
	}
	| compound_statement{
		$$ = $1;
		printf("reduce statement->compound_statement\n");
	}
	| IF
	expression 
	THEN
	statement 
	ELSE
	statement{
		$$ = newNode(NODE_statement_IF);
		addChild($$,$2);//the first child of if statement is the expression of condition
		addChild($$,$4);//the second one is statement of right condition
		addChild($$,$6);//third one is statement of worong condition
		printf("reduce statement->if expression then statement else statement\n"); 
	}
	| WHILE
	expression 
	DO
	statement{
		$$ = newNode(NODE_statement_WHILE);
		addChild($$,$2);//the first child of if statement is the expression of condition
		addChild($$,$4);//the second one is statement of right condition
		printf("reduce statement->while expression do statement\n");
	}
	| lambda{
		$$ = newNode(NODE_statement);//this is a node with no child
		printf("reduce statement->lambda\n");
	}
	;


variable : 
	id
	tail{
		$$ = newNode(NODE_variable);
		struct node *temp = newNode(K_id);
		temp->string = strdup($1);
		addChild($$,temp);//first child is the name of variable(mabe single one or array)
		addChild($$,$2);//second one is tail of variable(exist if it is an array)
		printf("reduce variable->id tail\n");
	}
	;

tail     : 
	LBRAC
	expression 
	RBRAC
	tail{
		addChild($4,$2);//here temp is the last
		$4->child = $2;//here make temp be the first child
		$$ = $4;
		// 12/14 A.M.02:13 expression should store the value to compute the value if it crosses the bound
		printf("reduce tail->[ expression ] tail\n");
	}
	| lambda{
		$$ = newNode(NODE_tail);
		printf("reduce tail->lambda\n");
	} 
	;

procedure_statement : 
	id{
		$$ = newNode(NODE_procedure_statement_single_id);
		struct node* temp = newNode(K_id);
		temp->string = strdup($1);
		addChild($$,temp);
		printf("reduce procedure_statement->id\n");
	}
	| 
	id
	LPAREN
	expression_list 
	RPAREN{
		$$ = newNode(NODE_procedure_statement_parameter);
		struct node* temp = newNode(K_id);
		temp->string = strdup($1);
		
		addChild($$,temp);
		
		addChild($$,$3);
		
		printf("reduce procedure_statement->id (expression_list)\n");
	}
	;

expression_list : 
	expression{
		
		$$ = newNode(NODE_expression_list);
		
		addChild($$,$1);
		
		printf("reduce expression_list->expression\n");
	}
	|expression_list 
	COMMA
	expression{
		
		addChild($1,$3);
		
		$$ = $1;
		printf("reduce expression_list->expression_list , expression\n");
	}
	;

expression : 
	simple_expression{
		$$ = newNode(NODE_expression_single);//if the expression doesn't have relation operator that's simple expression
		addChild($$,$1);
		printf("reduce expression->simple_expression\n");
	}
	| simple_expression 
	relop 
	simple_expression{
		$$ = newNode(NODE_expression_multi);
		addChild($$,$1);//the first operend
		addChild($$,$2);//the relation operator
		addChild($$,$3);//the second operend
		printf("reduce->simple_expression relop simple_expression\n");
	}
	;

simple_expression : 
	term{
		$$ = newNode(NODE_simple_expression_single);
		addChild($$,$1);
		printf("reduce simple_expression->term\n");
	}
	| simple_expression 
	addop 
	term{
		$$ = newNode(NODE_simple_expression_multi);
		addChild($$,$1);//the first operend
		addChild($$,$2);//the addition or substraction operator
		addChild($$,$3);//the second operend
		printf("reduce simple_expression-> simple_expression addop term\n");
	}
	;

term : factor{
		$$ = newNode(NODE_term_single);
		addChild($$,$1);
		printf("reduce term->factor\n");
	}
	| term 
	mulop 
	factor{
		$$ = newNode(NODE_term_multi);
		addChild($$,$1);//the first operend
		addChild($$,$2);//the mulitiplication or division operator
		addChild($$,$3);//the second operend
		printf("reduce term->term mulop factor\n");
	}
	;

factor : 
	id
	tail{
		struct node *temp = newNode(K_id);
		temp->string = strdup($1);
		$$ = newNode(NODE_factor_tail);
		addChild($$,temp);//first child is variable called
		addChild($$,$2);//second is tail(for array);
		printf("reduce factor->ID tail\n");
	}
	| id
	LPAREN
	expression_list 
	RPAREN{
		struct node *temp = newNode(K_id);
		temp->string = strdup($1);
		$$ = newNode(NODE_factor_expression_list);//maybe the function call in an expression
		addChild($$,temp);
		addChild($$,$3);
		printf("reduce factor->id (expression_list)\n");
	}
	| NUM{
		$$ = newNode(NODE_factor_NUM);
		addChild($$,$1);
		printf("reduce factor->NUM\n");
	}
	| MINUS NUM{
		$$ = newNode(NODE_factor_NUM);
		addChild($$,$1);
		printf("reduce factor->'-'NUM\n");
	}
	| LPAREN
	expression 
	RPAREN{
		$$ = newNode(NODE_factor_factor);
		addChild($$,$2);
		printf("reduce factor->(expression_list)\n");
	}
	| NOT
	factor{
		$$ = newNode(NODE_factor_not);//this factor is inverted
		addChild($$,$2);//only store the factor below
		printf("reduce factor->not factor\n");
	}
	;

addop : 
	PLUS{
		$$ = newNode(NODE_addop);
		$$->string = "+";
		printf("reduce addop->+\n");
	} 
	| MINUS{
		$$ = newNode(NODE_addop);
		$$->string = "-";
		printf("reduce addop->-\n");
	}
	;

mulop : STAR{
		$$ = newNode(NODE_mulop);
		$$->string = "*";
		printf("reduce mulop->*\n");
	} 
	| SLASH{
		$$ = newNode(NODE_mulop);
		$$->string = "/";
		printf("reduce mulop->/\n");
	}
	;


relop : LT{
		$$ = newNode(NODE_relop);
		$$->string = "<";
		printf("reduce relop-><\n");
	}
	| GT{
		$$ = newNode(NODE_relop);
		$$->string = ">";
		printf("reduce relop->>\n");
	}
	| EQUAL{
		$$ = newNode(NODE_relop);
		$$->string = "=";
		printf("reduce relop->=\n");
	}
	| LE{
		$$ = newNode(NODE_relop);
		$$->string = "<=";
		printf("reduce relop-><=\n");
	}
	| GE{
		$$ = newNode(NODE_relop);
		$$->string = ">=";
		printf("reduce relop->>=\n");
	}
	| notEQUAL{
		$$ = newNode(NODE_relop);
		$$->string = "!=";
		printf("reduce relop->!=\n");
	}
	;
NUM : CONST_INT{
		$$ = newNode(NUM_INT);
		$$->iValue = $1;
	}
	| CONST_STRING{
		$$ = newNode(NUM_STRING);
		$$->string = strdup($1);
	}
	| CONST_REAL{
		$$ = newNode(NUM_REAL);
		$$->rValue = $1;
	}
lambda : ;
%%
int yyerror( char *msg )
{
  fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d:\n", line_no);
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
  fprintf( stderr, "|--------------------------------------------------------------------------\n" );
  exit(-1);
}

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}


