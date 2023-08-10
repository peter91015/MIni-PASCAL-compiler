#ifndef __NODE_H__
#define __NODE_H__

typedef struct node;
enum ntype {
    VALUE_INVALID,             
    NODE_identifier_list,
	NODE_declaration,	
    NODE_declarations,              
    NODE_prog,                     
    NODE_type,
    NODE_standard_type,
	NODE_subprogram_declarations,
	NODE_subprogram_declaration,
	NODE_subprogram_head,
	NODE_arguments,
	NODE_parameter_list,
	NODE_parameter_list_single,
	NODE_optional_var,
	NODE_statement_IF,
	NODE_statement_WHILE,
	NODE_compound_statement,
	NODE_optional_statements,
	NODE_statement_list,
	NODE_statement,
	NODE_variable,
	NODE_tail,
	NODE_procedure_statement,
	NODE_procedure_statement_single_id,
	NODE_procedure_statement_parameter,
	NODE_expression_list,
	NODE_expression_single,
	NODE_expression_multi,
	NODE_simple_expression_single,
	NODE_simple_expression_multi,
	NODE_term_single,
	NODE_term_multi,
	NODE_factor_tail,
	NODE_factor_expression_list,
	NODE_factor_NUM,
	NODE_factor_not,
	NODE_factor_factor,
	NODE_addop,
	NODE_mulop,
	NODE_relop,
	empty_lambda,
    OP_ADD, 
    OP_SUB, 
    OP_MUL, 
    OP_DIV,
	OP_PLUS,
	OP_MINUS, 
	OP_STAR, 
	OP_SLASH, 
	OP_GT, 
	OP_EQUAL, 
	OP_LE, 
	OP_GE,
	OP_notEQUAL,
	OP_LT,
	K_PROGRAM,
	K_PROCEDURE, 
	K_ARRAY, 
	K_VAR, 
	K_OF, 
	K_FUNCTION,
	K_INTEGER, 
	K_REAL, 
	K_STRING, 
	K_DOTDOT, 
	K_RBRAC, 
	K_LBRAC,
	K_IF, 
	K_THEN, 
	K_ELSE, 
	K_WHILE, 
	K_DO, 
	K_PBEGIN, 
	K_END, 
	K_NOT, 
	K_ASSIGNMENT, 
	K_COLON, 
	K_SEMICOLON, 
	K_LPAREN, 
	K_RPAREN, 
	K_DOT, 
	K_COMMA,
	K_id,
	NUM_INT,
	NUM_REAL,
	NUM_STRING
};

// #include "symtab.h"
typedef struct node {
    int nodeType;
    struct node *parent;
    struct node *child;
    struct node *lsibling;
    struct node *rsibling;

    /* Attribute for NODE_TOKEN */
    int tokenType;

    /* items for Array */
    int idxstart;
    int idxend;
    int arraydepth;
    struct node *ref;

    /* Values for general use */
    int iValue;
    double rValue;
    char valueValid;
    char *string;
    
    /* Indicates which OP */
    char op;

};

struct node* newNode(int type);
void deleteNode(struct node* node);
void addChild(struct node *node, struct node *child);
void printTree(struct node *node, int ident);

#endif

