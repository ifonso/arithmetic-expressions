#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "AST.h"

int main() {
  char * first_expression = "(3+4)*2";
  printf("Expression: %s\n", first_expression);

  // Creating expression AST from infix expression
  TNode * ast_i = node_create_from_infix(first_expression);

  // Printing AST expression in infix notation
  printf("%s\n", node_get_infix(ast_i));

  // Printing AST expression in prefix notation
  printf("%s\n", node_get_prefix(ast_i));

  // Evaluating AST expression
  printf("Result: %d\n\n", eval(ast_i));

  // ------------ Creating AST from prefix expression ------------

  char * second_expression = "*+342";
  printf("Expression: %s\n", second_expression);

  // Creating expression AST from prefix expression
  TNode * ast_p = node_create_from_prefix(second_expression);

  // Printing AST expression in infix notation
  printf("%s\n", node_get_infix(ast_p));

  // Printing AST expression in prefix notation
  printf("%s\n", node_get_prefix(ast_p));

  // Evaluating AST expression
  printf("Result: %d\n\n", eval(ast_p));

  // Destroying AST
  destroy_ast(ast_i);
  destroy_ast(ast_p);

  return 0;
}