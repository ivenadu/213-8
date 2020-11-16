#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "reversestringnode.h"

struct ReverseStringNode_class ReverseStringNode_class_table = {
  // TODO initialization of class table
  ReverseStringNode_compareTo,
  StringNode_printNode,
  Node_insert,
  Node_print,
};

// TODO implementation of method(s) that ReverseStringNode overrides

int ReverseStringNode_compareTo(void* thisv, void* nodev) {
  struct StringNode* this = thisv;
  struct StringNode* node = nodev;
  return -1 * strcmp (this->s, node->s);
}

void* new_ReverseStringNode(char* s){
  struct ReverseStringNode * inst = malloc(sizeof(struct ReverseStringNode));
  inst->class = &ReverseStringNode_class_table;
  StringNode_ctor(inst, s);
  return inst;
}