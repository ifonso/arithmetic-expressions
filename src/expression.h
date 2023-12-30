#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "stack.h"

/** 
 * @brief Enum representando as possíveis operações para uma expressão.
**/
typedef enum {
  ADD, // Adição
  SUB, // Subtração
  MUL, // Multiplicação
  DIV, // Divisão
  NIL, // Nenhuma operação
} Operator;

/** 
 * @brief Enum usado para representar o lado de um valor em uma expressão.
**/
typedef enum {
  LHS, // Left-hand side
  RHS, // Right-hand side
} Side;

// --------------------------- Structs ---------------------------

/** 
 * @brief Struct representando um operando de uma expressão.
**/
typedef struct {
  unsigned int value;

  Side vs;     // Lado do valor
  Operator op; // Operação

} Operand;

/** 
 * @brief Struct que armazena uma expressão aritimética em uma stack.
**/
typedef struct {
  Stack * stack; // Stack que armazena a expressão

  char * infix;
  char * prefix;
} Expression;

// --------------------- Function declarations ---------------------

Expression * expression_create();
void expression_delete(Expression * expression);

void expression_push_operand(Expression * expression, unsigned int value, Side vs, Operator op);
// int evaluate_expression(Expression * expression);

char * infix_to_prefix(char * exp);

#endif /* EXPRESSION_H_ */