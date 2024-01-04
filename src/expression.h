#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "stack.h"

// --------------------------- Expression ---------------------------

typedef struct LNode LNode;
typedef struct Expression Expression;
typedef enum ExpressionType ExpressionType;

enum ExpressionType {
  INFIX,
  PREFIX
};

struct LNode {
  char term;
  struct LNode * next;
};

struct Expression {
  ExpressionType type;
  LNode * head;
  unsigned int size;
};

// --------------------- Function declarations ---------------------

Expression * expression_create_infix(const char * exp);

void expression_convert_to_prefix(Expression * exp);
void expression_destroy(Expression * exp);
void expression_print(Expression * exp);

#endif /* EXPRESSION_H_ */