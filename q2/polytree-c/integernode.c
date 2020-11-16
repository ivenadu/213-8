#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "integernode.h"

int IntegerNode_compare(void* thisv, void* nodev){
    return ((struct IntegerNode*)thisv)->i - ((struct IntegerNode*)nodev)->i;
}
void IntegerNode_printNode (void* thisv){
    printf("%d\n", ((struct IntegerNode*)thisv)->i);
}

struct IntegerNode_class IntegerNode_class_table = {
  IntegerNode_compare,
  IntegerNode_printNode,
  Node_insert,
  Node_print,
  Node_delete
};


void* new_IntegerNode(int v){
    struct IntegerNode* p = malloc(sizeof(struct IntegerNode));
    p->class = &IntegerNode_class_table;
    p->i = v;

    Node_ctor(p);
    return p;
}

long long IntegerNode_sum(void * thisv){
   struct IntegerNode* node = thisv;
   long long s = node->i;
    if (node->left != NULL)
      s += IntegerNode_sum(node->left);
    if (node->right != NULL)
      s += IntegerNode_sum(node->right);

    return s;
}
// TODO 
