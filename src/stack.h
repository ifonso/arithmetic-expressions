#ifndef STACK_H_
#define STACK_H_

/* Implementação genérica de uma stack */

typedef struct Stack Stack;
typedef struct Node Node;

struct Node {
  void * value;
  Node * next;
};

struct Stack {
  Node * top;
  unsigned int size;
};

// --------------------- Function declarations ---------------------

Stack * create_stack();
void delete_stack(Stack * stack);

void push(Stack * stack, void * value);
void * pop(Stack * stack);
void * peek(Stack * stack);

#endif /* STACK_H_ */