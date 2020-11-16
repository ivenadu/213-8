#ifndef __LOGGINGSTRINGNODE_H__
#define __LOGGINGSTRINGNODE_H__

#include "node.h"
// TODO
struct LoggingStringNode_class {
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)    (void*);
};
struct LoggingStringNode {
  struct LoggingStringNode_class* class;

  struct StringNode* left;
  struct StringNode* right;

  char* s;
};

void * new_LoggingStringNode(void *s);

#endif /*__LOGGINGSTRINGNODE_H__*/
