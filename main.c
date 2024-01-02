#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "AST.h"

int main() {
  char * expression = "(3+4)*2";

  // Creating expression AST from infix expression
  TNode * ast = node_create_from_infix(expression);

  // Printing AST expression in infix notation
  printf("%s\n", node_get_infix(ast));

  // Printing AST expression in prefix notation
  printf("%s\n", node_get_prefix(ast));

  // Evaluating AST expression
  printf("Result: %d\n", eval(ast));

  // Destroying AST
  destroy_ast(ast);

  return 0;
}