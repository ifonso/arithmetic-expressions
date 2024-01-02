#include "AST.h"
#include "stack.h"
#include "expression.h"

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

TNode * node_create_from_infix(char * infix) {
  Stack * stack = create_stack();  // Char operators stack
  Stack * output = create_stack(); // AST Stack

  for (int i = 0; i < strlen(infix); i++) {

    if (isdigit(infix[i])) {
      // Create number node
      TNode * num_node = node_create_number(infix[i] - '0');
      // pushing it to output then continue
      push(output, (void *)num_node);
      continue;
    }

    // Allocate a copy char
    char * c = malloc(sizeof(char) * 2);
    c[0] = '\0';
    strncpy(c, &infix[i], 1);

    if (infix[i] == '(') {
      // Pushing the copy to operator stack
      push(stack, (void *)c);
      continue;
    }

    if (is_operator(&infix[i])) {
      // while is not the highest precedence on stack
      while(
        stack->size != 0 &&
        *(char *)peek(stack) != '(' &&
        precedence((char *)peek(stack)) >= precedence(&infix[i])
      ) {
        // Getting operator
        Operator op = get_operator((char *)pop(stack));
        // Create a node with the last ones in output
        if (output->size < 2) {
          perror("Invalid expression");
          exit(1);
        }
        
        TNode * rhs = (TNode *)pop(output);
        TNode * lhs = (TNode *)pop(output);
        TNode * node = node_create_operation(op, lhs, rhs);
        // Adding new node to output
        push(output, (void *)node);
      }
      // pushing operator to stack
      push(stack, (void *)c);
      continue;
    }

    if (infix[i] == ')') {
      while (
        stack->size > 0 && 
        *(char *)peek(stack) != '('
      ) {
        // Getting operator
        Operator op = get_operator((char *)pop(stack));
        // Create a node with the last ones in output
        if (output->size < 2) {
          perror("Invalid expression");
          exit(1);
        }

        TNode * rhs = (TNode *)pop(output);
        TNode * lhs = (TNode *)pop(output);
        TNode * node = node_create_operation(op, lhs, rhs);
        // Adding new node to output
        push(output, (void *)node);
      }
      // removing '('
      pop(stack);
    }
  }

  while (stack->size > 0) {
    // Getting operator
    Operator op = get_operator((char *)pop(stack));
    // Create a node with the last ones in output
    if (output->size < 2) {
      perror("Invalid expression");
      exit(1);
    }

    TNode * rhs = (TNode *)pop(output);
    TNode * lhs = (TNode *)pop(output);
    TNode * node = node_create_operation(op, lhs, rhs);
    // Adding new node to output
    push(output, (void *)node);
  }

  return (TNode *)output->top->value;
}