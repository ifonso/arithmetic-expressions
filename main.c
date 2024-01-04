#include <stdio.h>
#include <stdlib.h>

#include "expression.h"

int main() {
  char * first_expression = "(3+4)*2";
  
  Expression * infix = expression_create_infix(first_expression);
  expression_print(infix);

  expression_convert_to_prefix(infix);
  expression_print(infix);

  return 0;
}