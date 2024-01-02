#ifndef AST_H_
#define AST_H_

typedef struct TNode TNode;
typedef struct Branch Branch;


typedef enum {
  ADD, // Adição
  SUB, // Subtração
  MUL, // Multiplicação
  DIV, // Divisão
} Operator;

typedef enum {
  AST_NUMBER,
  AST_OPERATION,
} Type;

// --------------------------- Structs ---------------------------

struct Branch {
  Operator op;

  struct TNode * left;
  struct TNode * right;
};

struct TNode {
  Type type;

  union  {
    unsigned int value;
    Branch branch;
  } value;
};

// --------------------- Function declarations ---------------------

TNode * node_create_number(unsigned int value);
TNode * node_create_operation(Operator op, TNode * left, TNode * right);
TNode * node_create_from_infix(char * infix);

void destroy_ast(TNode * node);

unsigned int eval(TNode * node);

void print_infix(TNode * node);
void print_prefix(TNode * node);

#endif /* AST_H_ */