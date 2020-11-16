#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "integernode.h"

int int_compare(void* thisv, void* nodev){
    return ((struct IntegerNode*)thisv)->i - ((struct IntegerNode*)nodev)->i;
}
void int_printNode (void* thisv){
    printf("%d\n", ((struct IntegerNode*)thisv)->i);
}

struct Node_class IntegerNode_class_table = {
  int_compare,
  int_printNode,
  Node_insert,
  Node_print,
};


void* new_IntegerNode(int v){
    struct IntegerNode* p = malloc(sizeof(struct IntegerNode));
    p->class = &IntegerNode_class_table;
    p->i = v;

    Node_ctor(p);
    return p;
}

int sum(void * thisv){
   struct IntegerNode* node = thisv;
   int s = node->i;
    if (node->left != NULL)
      s += sum(node->left);
    if (node->right != NULL)
      s += sum(node->right);

    return s;
}
// TODO 
