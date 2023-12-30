#include "expression.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -------- Lifecycle --------

Expression * expression_create() {
  Expression * expression = (Expression *) malloc(sizeof(Expression));

  if (expression == NULL) {
    perror("error while allocating expression.\n");
    exit(EXIT_FAILURE);
  }

  expression->stack = create_stack();

  return expression;
}

void expression_delete(Expression * expression) {
  delete_stack(expression->stack);
  free(expression);
}

// -------- Utils --------

char * strrev(const char * str) {
  int size = strlen(str);
  char * rev = (char *)malloc((size + 1) * sizeof(char));
  
  rev[0] = '\0';

  for (int i = size - 1; i >= 0; i--) {
    strncat(rev, &str[i], 1);
  }

  return rev;
}

int is_operator(char * c) {
  switch (*c) {
    case '+':
    case '-':
    case '*':
    case '/':
      return 1;
    default:
      return 0;
  }
}

int precedence(char * c) {
  switch (*c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

char * infix_to_prefix(char * exp) {
  return NULL;
}

// -------- Operations --------

void expression_push_operand(Expression * expression, unsigned int value, Side vs, Operator op) {
  if (expression->stack->top != NULL && op != NIL) {
    perror("error: base expression needs to be a value");
    exit(EXIT_FAILURE);
  }

  Operand * operand = (Operand *)malloc(sizeof(Operand));

  operand->value = value;
  operand->vs = vs;
  operand->op = op;

  push(expression->stack, operand);
}