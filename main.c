#include <stdio.h>
#include <stdlib.h>

#include "expression.h"

int main() {
  char * expression = "(1+2)*(3+4)";
  printf("%s\n", infix_to_prefix(expression));

  return 0;
}