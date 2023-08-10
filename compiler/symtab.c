#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *outfp;
char *program_name;
char *temp_list [20];
char *present_function;
int ind;//the variable for taking the index of variable in symboltabel
int ind_variable;//the variable for variable to store
int ind_temp_term1,ind_temp_term2, ind_temp_simple_expression1,ind_temp_simple_expression2;
int depth[20];
int mem_avail[11];//to record if this position is availible 
int local_count = 0;
int scope = 1;
int i;
int n_error = 0;

;//to keep the type of LHS
enum StdType type_variable_l,type_variable_r;
enum errortype et[26];
struct SymTable SymbolTable;
void reset_availible(void){
	int i=0;
	for(;i<10;i++)
		mem_avail[i] = 1;
}
int take_next_availible(void){
	int i=0;
	for(i=0;i<10;i++){
		if(mem_avail[i]){
			mem_avail[i] = 0;
			return i;
		}		
	}
	return -1;//there's no enough memory 
}
void pop_the_symbol(void){
	for(int a=SymbolTable.size-1;SymbolTable.entries[a].scope==scope;a--)
		SymbolTable.size--;//pop the variable since we are about to pop the scope;
	
}
void print_symboltable(void){//print the present content of symboltable
	for(int a=0;a<SymbolTable.size;a++){
		printf("SymbolTable.entries[%d].name = %s, ",a,SymbolTable.entries[a].name);
		switch(SymbolTable.entries[a].type){
			case TypeInt:
				printf("type = int ");
				
			break;
			case TypeReal:
				printf("type = real ");
			break;
			case Typestring:
				printf("type = string ");
			break;
			case Typefunction_int:
				printf("type = function_int ");
			break;
			case Typefunction_real:
				printf("type = function_real ");
			break;
			case Typefunction_string:
				printf("type = function_string ");
			break;
		}
		printf("scope = %d,",SymbolTable.entries[a].scope);
		if(SymbolTable.entries[a].scope>1)
		printf("position = %d\n", SymbolTable.entries[a].val_num);
		else if(SymbolTable.entries[a].scope == 1 && (SymbolTable.entries[a].type == TypeInt|| SymbolTable.entries[a].type == TypeReal|| SymbolTable.entries[a].type == Typestring))
		printf("global\n");
		else
		printf("function\n");
	}
}
int check_no_undef(char *id){
	for(int a=SymbolTable.size-1;a>=0;a--){
		if(strcmp(SymbolTable.entries[a].name,id)==0 && SymbolTable.entries[a].scope == scope){
			ind = a;//this number is the variable that we want to take
			return 1;//find the nearest and the same id in the symboltabel.
		}
		else if(strcmp(SymbolTable.entries[a].name,id)==0){
			ind = a;
			return 1;//we can just choose the id with the same name if we don't have that with the same scope and same name.
		}
	}
	return 0;//there's no such a variable declared
}
int check_no_dup_dec(char *id){
	for(int i=0;i<SymbolTable.size;i++){
		//printf("%dth id in symboltable is:%s\n",i,SymbolTable.entries[i].name);
		if(strcmp(SymbolTable.entries[i].name,id)==0 && SymbolTable.entries[i].scope == scope){//strcmp == 0 means the two strings are the same
			//printf("duplicated declatation\n");
			
			return 0;//the declaration of this id duplicates
		}
	}
	return 1;//this declaration is legal
}
struct SymTableEntry* findSymbol(char *s) {
    for(int i=0; i<SymbolTable.size; i++) {
        if(strcmp(s, SymbolTable.entries[i].name) == 0) {
            return &SymbolTable.entries[i];
        }
    }

    return 0;
}

struct SymTableEntry* addVariable(char *s, enum StdType type) {
    if(findSymbol(s) != 0) {
        printf("Error: duplicate declaration of variable %s\n", s);
        exit(0);
    }

    int index = SymbolTable.size;
    SymbolTable.size++;

    strcpy(SymbolTable.entries[index].name, s);
    SymbolTable.entries[index].type = type;
    
    return &SymbolTable.entries[index];
}

struct nodeType* nthChild(int n, struct node *node) {
    struct node *child = node->child;
    for(int i=1; i<n; i++) {
        child = child->rsibling;
    }
    return child;
}

void semanticCheck(struct node *node) {
	int size = 0;//the number of argument
	char *type_sym,*file_name;
	enum StdType temp_type;
	struct node *temp;
	switch(node->nodeType){
		case NODE_prog: //this is the main body of program
			reset_availible();
			SymbolTable.size = 0;
			scope = 1;//the scope is set to 1 initially
			program_name = strdup(node->child->string);
			file_name = strdup(node->child->string);
			outfp = fopen(strcat(file_name,".j"),"w");
			fprintf(outfp,".class public %s\n",node->child->string);
			fprintf(outfp,".super java/lang/Object \n");
			printf("-----------------------------------\n");
			printf("|declaration of global variable...|\n");
			printf("-----------------------------------\n");
			semanticCheck(node->child->rsibling->rsibling);//go to the declaration of prog
			printf("------------------------------\n");
			printf("|declaration of subprogram...|\n");
			printf("------------------------------\n");
			semanticCheck(node->child->rsibling->rsibling->rsibling);//go to the declaration for subprogram(function or procedure)
			printf("----------------------------\n");
			printf("|the statement of program...|\n");
			printf("----------------------------\n");
			present_function = strdup(node->child->string);
			fprintf(outfp,".method public static main([Ljava/lang/String;)V\n");
			fprintf(outfp,".limit stack 10\n");
			fprintf(outfp,".limit locals 10\n");
			semanticCheck(node->child->rsibling->rsibling->rsibling->rsibling);//go to the compound_statement of main body of program
			fprintf(outfp,"return\n");
			fprintf(outfp,".end method");
			if(n_error == 0){
				printf("there's no semantic error in this code!\n");
			}
			else{
				printf("there's %d errors in this program\n",n_error);
			}	
			print_symboltable();
		break;
		case NODE_identifier_list:
			i = 0;
			int debug_c=0;
			temp = node->child;//the type of child should be K_id
			do{
				//printf("the total size in symboltable = %d\n",SymbolTable.size);
				//printf("i = %d and the id about to be tested: %s \n",i,temp->string);
				if(check_no_dup_dec(temp->string)){
					temp_list[i] = strdup(temp->string);
					printf("\tid: %s,scope = %d\n",temp_list[i],scope);
				}
				else{
					et[n_error] = e_dup;
					n_error++;
					printf("duplicated id:%s\n",temp->string);
				}
				i++;
				/*for(int j=0;j<i;j++)
					printf("temp_list[%d]: %s\n",j,temp_list[j]);*/
				temp = temp->rsibling;
				
			}while(temp !=node->child);//here i keeps for the size of the id_list		
		break;
		case NODE_declaration:
			switch(node->child->rsibling->tokenType){
				case K_INTEGER:
					temp_type = TypeInt;
					if(node->child->rsibling->arraydepth>0)
						printf("Int Array:\n");
					else{
						type_sym = "I";
						printf("Int :\n");
					}
						
				break;
				case K_REAL:
					if(node->child->rsibling->arraydepth>0)
						printf("Real Array:\n");
					else{
						type_sym = "F";
						printf("Real :\n");
					}
						
					temp_type = TypeReal;
				break;
				case K_STRING:
					if(node->child->rsibling->arraydepth>0)
						printf("String Array:\n");
					else{
						type_sym = "S";
						printf("String :\n");
					}
						
					temp_type = Typestring;
				break;
			}//record the type of the declaration row
			
			semanticCheck(node->child);//go to the id_list of the declaration
			
			for(int j=0;j<i;j++){
				SymbolTable.entries[j+SymbolTable.size].name = strdup(temp_list[j]);
				SymbolTable.entries[j+SymbolTable.size].type = temp_type;
				SymbolTable.entries[j+SymbolTable.size].scope= scope;
				SymbolTable.entries[j+SymbolTable.size].arraydepth = node->child->rsibling->arraydepth;
				SymbolTable.entries[j+SymbolTable.size].ref = node->child->rsibling->ref;//if depth ==0 there should be nothing
				SymbolTable.entries[j+SymbolTable.size].start = node->child->rsibling->idxstart ;
				SymbolTable.entries[j+SymbolTable.size].end   = node->child->rsibling->idxend   ;
				if(scope == 1){
					fprintf(outfp,".field public static %s %s\n",temp_list[j],type_sym);//global variable declaration
				}
			}
			SymbolTable.size+=i;//update the size of symbol table
			i=0;//reset i 
		break;
		case NODE_declarations:
			//every "declarations" contains many declarations with single type declared and several arguments 
			temp = node->child;//that should be the type of declaration
			
			//int temp_num = 0;
			if(temp)
			do{
				//printf("problem id %d\n",temp_num);
				semanticCheck(temp);//check each declaration row  
				temp = temp->rsibling;
			}while(temp!=node->child);
			else//the declaration is null
				printf("\"there's no extra declaration in this scope\"\n");
			
		break;
		case NODE_subprogram_declarations:
			
			temp = node->child;
			if(temp){
				do{
					semanticCheck(temp);
					temp = temp->rsibling;
				}while(temp!=node->child);
			}
			//there is several declarations in "subprogram declarations"
		break;
		case NODE_subprogram_declaration:
			//subprogram declaration should contain id, parameter and output type and the variable declared in it.
			scope++;//because we go to next scope from global one.
			semanticCheck(node->child);//go to subprogram_head which contain id and parameter and type
			//printf("go to the declaration of subprogram\n");
			temp = node->child->rsibling;

			temp = temp->child;
			printf("find problem 1\n");
			semanticCheck(node->child->rsibling);//declarations
			printf("find problem 2\n");
			//printf("the symboltable before pop the subprogram:\n");
			print_symboltable();
			semanticCheck(node->child->rsibling->rsibling);//go to the fucking compound_statement of subprogram
			printf("exit the function\n");
			pop_the_symbol();
			//printf("the symboltable after pop the subprogram:\n");
			//print_symboltable();
			scope--;//back to the global field
		break;
		case NODE_subprogram_head:
			printf("function %s:",node->child->string);
			enum StdType temp_function_type;
			switch(node->child->lsibling->tokenType){
				case K_INTEGER:
					printf("type: int\n");
					temp_function_type = Typefunction_int;
				break;
				case K_REAL:
					printf("type: real\n");
					temp_function_type = Typefunction_real;
				break;
				case K_STRING:
					printf("type: string\n");
					temp_function_type = Typefunction_string;
				break;
			}
			if(check_no_dup_dec(node->child->string)){
				SymbolTable.entries[SymbolTable.size].name       = strdup(node->child->string);
				SymbolTable.entries[SymbolTable.size].type       = temp_function_type;
				SymbolTable.entries[SymbolTable.size].scope      = 1;
				SymbolTable.entries[SymbolTable.size].arraydepth = 0;
				SymbolTable.entries[SymbolTable.size].ref        = NULL;
				SymbolTable.entries[SymbolTable.size].start      = 0;
				SymbolTable.entries[SymbolTable.size].end        = 0;
				SymbolTable.entries[SymbolTable.size].val_num    = -1;//function should not have memory space
				SymbolTable.size++;
				semanticCheck(node->child->rsibling);//find the prameter of the function
				present_function = strdup(node->child->string);
			}
			else {
				et[n_error] = e_dup;//error occurs here must be duplication of declaration
				n_error++;
			}
		break;
		case NODE_arguments:
			if(node->child){
				printf("parameter in this function :\n");
				semanticCheck(node->child);//should go to NODE_parameter_list
				printf("end of displaying parameter\n");
			}
			else
				printf("there's no parameter passed in the function\n");
		break;
		case NODE_parameter_list:
			//parameter_list includes several single parameter_list
			temp = node->child;
			if(temp)
				do{
					semanticCheck(temp);//shoud go to NODE_parameter_list_single
					temp = temp->rsibling;
				}while(temp!=node->child);
			
		break;
		case NODE_parameter_list_single:
			//this case should be similar to NODE_declaration since both them have only one id_list and one type
			switch(node->child->rsibling->tokenType){//check the type
				case K_INTEGER:
					temp_type = TypeInt;
					if(node->child->rsibling->arraydepth>0)
						printf("Int Array:\n");
					else
						printf("Int :\n");
				break;
				case K_REAL:
					if(node->child->rsibling->arraydepth>0)
						printf("Real Array:\n");
					else
						printf("Real :\n");
					temp_type = TypeReal;
				break;
				case K_STRING:
					if(node->child->rsibling->arraydepth>0)
						printf("String Array:\n");
					else
						printf("String :\n");
					temp_type = Typestring;
				break;
			}//record the type of the declaration row
			
			semanticCheck(node->child);//go to the id_list of the declaration
			
			for(int j=0;j<i;j++){
				SymbolTable.entries[j+SymbolTable.size].name = strdup(temp_list[j]);
				SymbolTable.entries[j+SymbolTable.size].type = temp_type;
				SymbolTable.entries[j+SymbolTable.size].scope= scope;
				SymbolTable.entries[j+SymbolTable.size].arraydepth = node->child->rsibling->arraydepth;
				SymbolTable.entries[j+SymbolTable.size].ref = node->child->rsibling->ref;//if depth ==0 there should be nothing
				SymbolTable.entries[j+SymbolTable.size].start = node->child->rsibling->idxstart ;
				SymbolTable.entries[j+SymbolTable.size].end   = node->child->rsibling->idxend   ;
				SymbolTable.entries[j+SymbolTable.size].val_num = scope>1?take_next_availible():-1;//global variable doesn't need variable number
			}
			SymbolTable.size+=i;//update the size of symblo table
			i=0;//reset i 
		break;
		case NODE_compound_statement:
			//should check every
			scope++;
			semanticCheck(node->child);
			scope--;
		break;
		case NODE_statement_list:
			//there are several statements under the statement_list
			temp = node->child;
			if(temp)
				do{
					semanticCheck(temp);//travel all the statement 
					temp = temp->rsibling;
				}while(temp!=node->child);
			else
				printf("there's no statement in this scope\n");
		break;
		case NODE_statement:
			//printf("visit NODE_statement\n");
			temp = node->child;//temp is the variable of LHS
			if(temp){
				semanticCheck(temp);//go to the variable to be assigned
				enum StdType type_LHS = type_variable_l;//type_LHS  is the type of LHS
				printf("present function name:%s\n",present_function);
				printf("LHS :%s\n",temp->child->string);
				if((type_LHS == Typefunction_int || type_LHS == Typefunction_real || type_LHS == Typefunction_string) && strcmp(present_function,temp->child->string)){//this case is that the variable is just function but not that one of where it's in
					et[n_error] = e_wrong_type;
					n_error++;
					printf("the type of LHS %s is function type\n",temp->child->string);
				}
				else {
					semanticCheck(temp->rsibling);//check if the type of expression is the same as variable
					switch(type_LHS){
						case Typefunction_int:
							if(type_variable_l != TypeInt){
								et[n_error] = e_wrong_type;
								n_error++;
								printf("the type of variable %s doesn't match RHS\n",temp->child->string);
							}
						break;
						case Typefunction_real:
							if(type_variable_l != TypeReal){
								et[n_error] = e_wrong_type;
								n_error++;
								printf("the type of variable %s doesn't match RHS\n",temp->child->string);
							}
						break;
						case Typefunction_string:
							if(type_variable_l != Typestring){
								et[n_error] = e_wrong_type;
								n_error++;
								printf("the type of variable %s doesn't match RHS\n",temp->child->string);
							}
						break;
						default:
							if(type_LHS != type_variable_l){
								et[n_error] = e_wrong_type;
								n_error++;
								printf("the type of variable %s doesn't match RHS\n",temp->child->string);
							}
							else{
								switch(type_LHS){
									case TypeInt:
										type_sym = SymbolTable.entries[ind_variable].scope >1? "i":"I";
									break;
									case TypeReal:
										type_sym = SymbolTable.entries[ind_variable].scope >1? "f":"F";
									break;
								}
								if(SymbolTable.entries[ind_variable].scope >1)
								fprintf(outfp,"%sstore %d\n",type_sym,SymbolTable.entries[ind_variable].val_num);
								else
								fprintf(outfp,"putstatic %s\/%s %s\n",program_name,SymbolTable.entries[ind_variable].name,type_sym);
							}
						break;
					}
					ind_variable = -1;//reset
				}
					
			}
		break;
		case NODE_expression_single:
			//printf("visit NODE_expression_single\n");
			semanticCheck(node->child);//the global variable_type will keep
		break;
		case NODE_expression_multi://multi expression may contain operation of relation
			//printf("visit \n");
			//printf("visit NODE_expression_multi\n");
		break;
		case NODE_variable:
			//printf("visit NODE_variable\n");
			if(check_no_undef(node->child->string)){
				//printf("%s\n",SymbolTable.entries[ind].name);
				type_variable_l = SymbolTable.entries[ind].type;//save the type to check if the type is the same as expression's
				ind_variable = ind;// keep the ind
			}
			else{
				et[n_error] = e_undef;//this variable is undefined
				n_error++;
				printf("the variable %s is undefined\n");
			}
		break;
		case NODE_simple_expression_single:
			//printf("visit NODE_simple_expression_single\n");
			semanticCheck(node->child);
		break;
		case NODE_simple_expression_multi://muti simple_expression may contain operation of addtion or substration
			//printf("visit NODE_simple_expression_multi\n");
			semanticCheck(node->child);
			enum StdType type_l = type_variable_l;
			semanticCheck(node->child->rsibling->rsibling);
			if(type_l != type_variable_l || type_l == Typeerror) 
				type_variable_l = Typeerror;
			else{
				switch(type_l){
					case TypeInt:
						type_sym = "i";
					break;
					case TypeReal:
						type_sym = "f";
					break;
				}
				if(!strcmp(node->child->rsibling->string,"+"))
					fprintf(outfp,"%sadd\n",type_sym);
				else if (!strcmp(node->child->rsibling->string,"-")){
					fprintf(outfp,"%ssub\n",type_sym);//b-a
				}
			}
		break;
		case NODE_term_single:
			//printf("visit NODE_term_single:\n");
			semanticCheck(node->child);
		break;
		case NODE_term_multi://multi term may contain operation of multiplication or division
			//printf("visit NODE_term_multi:\n");
			semanticCheck(node->child);
			enum StdType type_lh = type_variable_l;
			semanticCheck(node->child->rsibling->rsibling);
			if(type_lh != type_variable_l || type_lh == Typeerror ) 
				type_variable_l = Typeerror;
			else{
				switch(type_lh){
					case TypeInt:
						type_sym = "i";
					break;
					case TypeReal:
						type_sym = "f";
					break;
				}
				if(!strcmp(node->child->rsibling->string,"*"))//the case of *	
					fprintf(outfp,"%smul\n",type_sym);
				else if (!strcmp(node->child->rsibling->string,"/")){// the case of /
					/*int reg1 = take_next_availible();// take the number of most top one in stack
					int reg2 = take_next_availible();// take the second one
					fprintf(outfp,"%sstore %d\n",type_sym,reg1);
					fprintf(outfp,"%sstore %d\n",type_sym,reg2);
					fprintf(outfp,"%sload  %d\n",type_sym,reg1);
					fprintf(outfp,"%sload  %d\n",type_sym,reg2);
					mem_avail[reg1] = 1;
					mem_avail[reg2] = 1;*/
					fprintf(outfp,"%sdiv\n",type_sym);
					/*fprintf(outfp,"%sdiv\n",type_sym);// b/a
					if(!strcmp(type_sym,"i"))
						fprintf(outfp,"sipush 1\n");	 
					else if (!strcmp(type_sym,"f"))
						fprintf(outfp,"ldc 1.0\n");		
					fprintf(outfp,"%sdiv\n",type_sym);// 1/(b/a) = a/b*/
				}
			
			}
		break;
		case NODE_factor_tail://alomost equal to NODE_variable
			//printf("visit NODE_factor_tail:\n");
			if(check_no_undef(node->child->string)){
				type_variable_l = SymbolTable.entries[ind].type;//save the type to check if the type is the same as expression's
				switch(SymbolTable.entries[ind].type){
					case TypeInt:
						type_sym = SymbolTable.entries[ind].scope >1?"i":"I";
					break;
					case TypeReal:
						type_sym = SymbolTable.entries[ind].scope >1?"f":"F";
					break;
					default:
						//there's no other type(?)
					break;
				}
				if(SymbolTable.entries[ind].scope >1)
					fprintf(outfp,"%sload %d\n",type_sym,SymbolTable.entries[ind].val_num);
				else 
					fprintf(outfp,"getstatic %s\/%s %s\n",program_name,SymbolTable.entries[ind].name,type_sym);
				//if(SymbolTable.entries[ind].arraydepth != 0){}//need to do more things if there's tail
			}
			else{
				et[n_error] = e_undef;
				n_error++;
				printf("undefined variable: \n",node->child->string);
			}
		break;
		case NODE_factor_expression_list:
		break;
		case NODE_factor_NUM:
			//printf("visit NODE_factor_NUM:\n");
			switch(node->child->nodeType){
				case NUM_INT:
					printf("the type of the constant is integer\n");
					type_variable_l = TypeInt; 
					fprintf(outfp,"sipush %d\n",node->child->iValue);
				break;
				case NUM_REAL:
					printf("the type of the constant is real\n");
					type_variable_l = TypeReal;
					fprintf(outfp,"ldc %f\n",node->child->rValue);
				break;
				case NUM_STRING:
					printf("the type of the constant is string\n");
					type_variable_l = Typestring;
				break;
				default:
					printf("error \n");
					type_variable_l = Typeerror;
				break;
			}
		break;
		case NODE_factor_factor: //this case is that factor's child is another expression
			//printf("visit NODE_factor_factor\n");
			semanticCheck(node->child);
		break;
		case NODE_factor_not:
		break;
	}
}