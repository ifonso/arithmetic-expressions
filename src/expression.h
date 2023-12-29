#ifndef EXPRESSION_H_
#define EXPRESSION_H_

/** 
 * @brief Enum representando as possíveis operações para uma expressão.
**/
typedef enum {
  ADD, // Adição
  SUB, // Subtração
  MUL, // Multiplicação
  DIV, // Divisão
} Operation;

/** 
 * @brief Struct representando uma expressão aritimética.
**/
typedef struct {
  Operation op;

  unsigned int lhs;  // left-hand side operand of the expression
  unsigned int rhs;  // right-hand side operand of the expression

} Expression;

// --------------------- Function declarations ---------------------

/**
 * @brief Cria uma expressão simples com os parâmetros dados.
 * 
 * @param op A operação da expressão.
 * @param lhs O operando do lado esquerdo da expressão.
 * @param rhs O operando do lado direito da expressão.
 * @return `Expression` A expressão criada.
**/
Expression create_expression(Operation op, unsigned int lhs, unsigned int rhs);

/**
 * @brief Avalia a expressão dada.
 * 
 * @param expression Um ponteiro para a expressão a ser avaliada.
 * @return `int` O resultado da expressão.
**/
int evaluate_expression(Expression * expression);

/**
 * @brief Imprime a expressão aritimética dada.
 * 
 * @param expression Um ponteiro para a estrutura de expressão a ser impressa.
**/
void print_expression(Expression * expression);

#endif /* EXPRESSION_H_ */