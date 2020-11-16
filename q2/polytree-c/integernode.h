#ifndef __INTEGERNODE_H__
#define __INTEGERNODE_H__

// TODO
struct IntegerNode {
  struct Node_class* class;

  // instance variables defined in super class(es)
  struct IntegerNode* left;
  struct IntgerNode* right;

  // instance variables defined in this class
  int i;
};

void* new_IntegerNode(int v);

int sum(void *thisv);

#endif /*__INTEGERNODE_H__*/
