#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "AST.h"

int main() {
  char * expression = "(3+4)*2";

  TNode * ast = node_create_from_infix(expression);

  printf("Infix: %s\n", expression);

  printf("Result: %d\n", eval(ast));

  return 0;
}