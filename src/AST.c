#include "AST.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -------- Utils --------

Operator get_operator(const char * c) {
  switch (*c) {
    case '+': return ADD;
    case '-': return SUB;
    case '*': return MUL;
    case '/': return DIV;
    default:
      perror("Invalid operator");
      exit(1);
  }
}

// -------- Functions --------

TNode * node_create_number(unsigned int value) {
  TNode * node = (TNode *)malloc(sizeof(TNode));
  node->type = AST_NUMBER;
  node->value.value = value;
  return node;
}

TNode * node_create_operation(Operator op, TNode * left, TNode * right) {
  TNode * node = (TNode *)malloc(sizeof(TNode));
  node->type = AST_OPERATION;
  node->value.branch.op = op;
  node->value.branch.left = left;
  node->value.branch.right = right;
  return node;
}

void destroy_ast(TNode * node) {
  if (node->type == AST_OPERATION) {
    destroy_ast(node->value.branch.left);
    destroy_ast(node->value.branch.right);
  }
  free(node);
}

unsigned int eval(TNode * node) {
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

// -------- expression utility functions --------

TNode * node_create_from_postfix(char * prefix) {
  return NULL;
}