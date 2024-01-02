#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack * create_stack() {
  Stack * stack = (Stack *) malloc(sizeof(Stack));

  if (stack == NULL) {
    perror("error while allocating stack.\n");
    exit(EXIT_FAILURE);
  }

  stack->top = NULL;
  stack->size = 0;
  
  return stack;
}

void delete_stack(Stack * stack) {
  Node * current = stack->top;
  Node * next = NULL;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  free(stack);
}

void push(Stack * stack, void * value) {
  Node * node = (Node *) malloc(sizeof(Node));

  if (node == NULL) {
    perror("error while allocating node.\n");
    exit(EXIT_FAILURE);
  }

  node->value = value;
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

void * pop(Stack * stack) {
  if (stack->size == 0) {
    perror("error while popping from stack: stack is empty.\n");
    exit(EXIT_FAILURE);
  }

  Node * node = stack->top;
  void * value = node->value;

  stack->top = node->next;
  stack->size--;

  free(node);

  return value;
}

void * peek(Stack * stack) {
  if (stack == NULL || stack->top == NULL) {
    perror("error while peeking from stack: stack is empty.\n");
    exit(EXIT_FAILURE);
  }
  return stack->top->value;
}