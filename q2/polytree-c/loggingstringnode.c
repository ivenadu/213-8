#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

// TODO
void my_insert(void* thisv, void* nodev) {
    printf("insert %s\n", ((struct LoggingStringNode*) nodev)->s);
    Node_insert(thisv, nodev);
}

struct StringNode_class LoggingStringNode_class_table = {
  StringNode_compareTo,
  StringNode_printNode,
  //my_insert,
  my_insert,
  Node_print,
};

void * new_LoggingStringNode(void *s){
    struct LoggingStringNode* p = malloc(sizeof(struct LoggingStringNode));
    p->class = &LoggingStringNode_class_table;
    StringNode_ctor(p, s);
    return p;
}
