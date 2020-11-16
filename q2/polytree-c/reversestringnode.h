#ifndef __REVERSESTRINGNODE_H__
#define __REVERSESTRINGNODE_H__

#include "stringnode.h"

struct ReverseStringNode_class {
  // TODO add function pointers
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)     (void*);
};
extern struct ReverseStringNode_class ReverseStringNode_class_table;

struct ReverseStringNode;
struct ReverseStringNode {
  struct ReverseStringNode_class* class;

  // instance variables defined in super class(es)
  struct StringNode* left;
  struct StringNode* right;

  char* s;
};

int ReverseStringNode_compareTo(void*, void*);

void* new_ReverseStringNode(char*);

#endif /*__REVERSESTRINGNODE_H__*/
