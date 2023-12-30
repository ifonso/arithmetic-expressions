#include "AST.h"

#include <stdio.h>
#include <stdlib.h>

Node * node_create_number(unsigned int value) {
  Node * node = (Node *)malloc(sizeof(Node));
  node->type = AST_NUMBER;
  node->value.value = value;
  return node;
}

Node * node_create_operation(Operator op, Node * left, Node * right) {
  Node * node = (Node *)malloc(sizeof(Node));
  node->type = AST_OPERATION;
  node->value.branch.op = op;
  node->value.branch.left = left;
  node->value.branch.right = right;
  return node;
}

void destroy_ast(Node * node) {
  if (node->type == AST_OPERATION) {
    destroy_ast(node->value.branch.left);
    destroy_ast(node->value.branch.right);
  }
  free(node);
}

unsigned int eval(Node * node) {
  if (node->type == AST_NUMBER) return node->value.value;

  unsigned int left = eval(node->value.branch.left);
  unsigned int right = eval(node->value.branch.right);

  switch (node->value.branch.op) {
    case ADD: return left + right;
    case SUB: return left - right;
    case MUL: return left * right;
    case DIV: return left / right;
  }
}