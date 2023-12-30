#ifndef AST_H_
#define AST_H_

typedef struct Node Node;
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

  struct Node * left;
  struct Node * right;
};

struct Node {
  Type type;

  union  {
    unsigned int value;
    Branch branch;
  } value;
};

// --------------------- Function declarations ---------------------

Node * node_create_number(unsigned int value);
Node * node_create_operation(Operator op, Node * left, Node * right);

void destroy_ast(Node * node);

unsigned int eval(Node * node);

#endif /* AST_H_ */