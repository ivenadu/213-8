#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

void LoggingStringNode_insert(void* thisv, void* nodev) {
    printf("insert %s\n", ((struct LoggingStringNode*) nodev)->s);
    Node_insert(thisv, nodev);
}

struct LoggingStringNode_class LoggingStringNode_class_table = {
  StringNode_compareTo,
  StringNode_printNode,
  LoggingStringNode_insert,
  Node_print,
  Node_delete
};

void * new_LoggingStringNode(void *s){
    struct LoggingStringNode* p = malloc(sizeof(struct LoggingStringNode));
    p->class = &LoggingStringNode_class_table;
    StringNode_ctor(p, s);
    return p;
}
