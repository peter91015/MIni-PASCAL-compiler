#ifndef __SYMTAB_H___
#define __SYMTAB_H___

enum StdType {TypeInt, TypeReal, Typefunction_int,Typefunction_real,Typefunction_string, Typestring,Typeerror};
enum errortype{e_dup,e_undef,e_wrong_type};
struct SymTableEntry {
    char *name;
	int scope;
	int arraydepth;
	int start;
	int end;
	int val_num;//record the place where they are in JVM
	struct node *ref;
    enum StdType type;
};

struct SymTable {
    int size;
    struct SymTableEntry entries[100];
};
//orinciple of symtable: just like a ""
extern struct SymTable SymbolTable;

#include "node.h"
void semanticCheck(struct node* node);

#endif

