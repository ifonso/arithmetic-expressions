#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "AST.h"

int main() {
  char * expression = "(3+4)*2";

  // Creating expression AST from infix expression
  TNode * ast = node_create_from_infix(expression);

  // Printing AST expression in infix notation
  print_prefix(ast);
  printf("\n");

  // Printing AST expression in prefix notation
  print_infix(ast);
  printf("\n");

  // Evaluating AST expression
  printf("Result: %d\n", eval(ast));

  // Destroying AST
  destroy_ast(ast);

  return 0;
}