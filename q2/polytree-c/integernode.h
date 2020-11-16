#ifndef __INTEGERNODE_H__
#define __INTEGERNODE_H__

// TODO
struct IntegerNode {
  struct Node_class* class;

  struct IntegerNode* left;
  struct IntgerNode* right;

  int i;
};

void* new_IntegerNode(int v);

long long IntegerNode_sum(void *thisv);

#endif /*__INTEGERNODE_H__*/
