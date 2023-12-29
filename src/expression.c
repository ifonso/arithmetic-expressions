#include "expression.h"

#include <stdio.h>
#include <stdlib.h>

Expression create_expression(Operation op, unsigned int lhs, unsigned int rhs) {
  Expression e = {
    .op = op,
    .lhs = lhs,
    .rhs = rhs,
  };
  
  return e;
}

int evaluate_expression(Expression * expression) {
  switch (expression->op) {
    case ADD:
      return expression->lhs + expression->rhs;
    case SUB:
      return expression->lhs - expression->rhs;
    case MUL:
      return expression->lhs * expression->rhs;
    case DIV:
      return expression->lhs / expression->rhs;
  }
}

void print_expression(Expression * expression) {
  switch (expression->op) {
    case ADD:
      printf("%d + %d\n", expression->lhs, expression->rhs);
      break;
    case SUB:
      printf("%d - %d\n", expression->lhs, expression->rhs);
      break;
    case MUL:
      printf("%d * %d\n", expression->lhs, expression->rhs);
      break;
    case DIV:
      printf("%d / %d\n", expression->lhs, expression->rhs);
  }
}