#ifndef __STRINGNODE_H__
#define __STRINGNODE_H__

struct StringNode_class {
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)     (void*);
};
extern struct StringNode_class StringNode_class_table;

struct StringNode;
struct StringNode {
  struct StringNode_class* class;

  struct StringNode* left;
  struct StringNode* right;

  char* s;
};

void StringNode_ctor(void*, char*);
int StringNode_compareTo(void*, void*);
void StringNode_printNode(void*);

void* new_StringNode(char*);

#endif /*__STRINGNODE_H__*/
