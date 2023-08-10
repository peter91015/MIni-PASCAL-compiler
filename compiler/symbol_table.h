#ifndef __SYM_H__
#define __SYM_H__

typedef struct sym_node{
	int type;
	struct sym_node *child;
	struct sym_node *lsibiling;
};
#endif