#ifndef __INTEGERNODE_H__
#define __INTEGERNODE_H__

// TODO
struct IntegerNode_class {
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)    (void*);
  int (*sum)        (void*);
};
struct IntegerNode {
  struct IntegerNode_class* class;

  struct IntegerNode* left;
  struct IntgerNode* right;

  int i;
};

void* new_IntegerNode(int v);

int IntegerNode_sum(void *thisv);

#endif /*__INTEGERNODE_H__*/
