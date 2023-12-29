#include "expression.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Testes
  Expression e = create_expression(ADD, 1, 2);
  print_expression(&e);
  printf("= %d\n", evaluate_expression(&e));

  return 0;
}