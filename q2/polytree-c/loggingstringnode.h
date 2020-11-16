#ifndef __LOGGINGSTRINGNODE_H__
#define __LOGGINGSTRINGNODE_H__

#include "node.h"
// TODO
struct LoggingStringNode {
  struct StringNode_class* class;

  // instance variables defined in super class(es)
  struct StringNode* left;
  struct StringNode* right;

  // instance variables defined in this class
  char* s;
};

void * new_LoggingStringNode(void *s);

#endif /*__LOGGINGSTRINGNODE_H__*/
