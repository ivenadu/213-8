#ifndef __REVERSESTRINGNODE_H__
#define __REVERSESTRINGNODE_H__

#include "stringnode.h"
/**
 * struct definition of class and external definition of class table
 */
struct ReverseStringNode_class {
  // TODO add function pointers
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
};
extern struct ReverseStringNode_class ReverseStringNode_class_table;

/**
 * struct definition of object
 */
struct ReverseStringNode;
struct ReverseStringNode {
  // TODO add class pointer and 
  // variables that are stored in instances of this class (including those introduced by super class)
  struct ReverseStringNode_class* class;

  // instance variables defined in super class(es)
  struct StringNode* left;
  struct StringNode* right;

  // instance variables defined in this class
  char* s;
};

/**
 * definition of methods implemented by this class
 */
int ReverseStringNode_compareTo(void*, void*);

/**
 * definition of new for class
 */
void* new_ReverseStringNode(char*);

#endif /*__REVERSESTRINGNODE_H__*/
