#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct Node_class Node_class_table = {
  NULL,
  NULL,
  Node_insert,
  Node_print,
  Node_delete
};

void Node_ctor(void* thisv) {
  struct Node* this = thisv;
  this->left = NULL;
  this->right = NULL;
}

void Node_delete(void* thisv){
  struct Node* node = thisv;
  if(node->left) Node_delete(node->left);
  if(node->right) Node_delete(node->right);

  free(node);
}

void Node_insert(void* thisv, void* nodev) {
  struct Node* this = thisv;
  struct Node* node = nodev;
  int c = this->class->compareTo(this, node);
  if (c > 0) {
    if (this->left == NULL)
      this->left = node;
    else
      this->class->insert(this->left, node);
  } else {
    if (this->right == NULL)
      this->right = node;
    else
      this->class->insert(this->right, node);
  }
}

void Node_print(void* thisv) {
  struct Node* this = thisv;
  if (this->left != NULL)
    this->class->print(this->left);
  this->class->printNode(this);
  if (this->right != NULL)
    this->class->print(this->right);
}

