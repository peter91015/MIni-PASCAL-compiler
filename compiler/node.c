#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

struct node* newNode(int type) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->nodeType = type;
    node->valueValid = VALUE_INVALID;
    node->string = NULL;
    node->parent = NULL;
    node->child = NULL;
    node->lsibling = node;
    node->rsibling = node;
    return node;
}

void addChild(struct node *node, struct node *child) {
    child->parent = node;
    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->lsibling = node->child->lsibling;
        child->rsibling = node->child;
        node->child->lsibling->rsibling = child;
        node->child->lsibling = child;
    }
}

void deleteNode(struct node *node) {
    if(node->string != NULL)
        free(node->string);
    free(node);
}

void printTree(struct node *node, int ident) {
    static char blank[1024];
    for(int i=0; i<ident; i++)
        blank[i] = ' ';
    blank[ident] = 0;

    switch(node->nodeType) {
        case OP_ADD:
            printf("%s/ADD\n", blank);
            break;
        case OP_SUB:
            printf("%s/SUB\n", blank);
            break;
        case OP_MUL:
            printf("%s/MUL\n", blank);
            break;
        case OP_DIV:
            printf("%s/DIV\n", blank);
            break;
        default:
            printf("%sdefault:%d\n", blank, node->nodeType);
          break;
    }

    struct node *child = node->child;
    if(child != NULL) {
        do {
            printTree(child, ident);
            child = child->rsibling;
        } while(child != node->child);
    }
}

