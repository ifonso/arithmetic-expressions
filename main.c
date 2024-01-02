#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "AST.h"

int main() {
  char * expression = "(1+2)*(3+4)";
  char * postfix = shunting_yard(expression);

  printf("Infix: %s\n", expression);
  printf("Postfix: %s\n", postfix);

  return 0;
}