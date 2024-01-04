#include "expression.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_OUT_SIZE 256

// -------- Utils --------

char * strrev(const char * str) {
  int size = strlen(str);
  char * rev = (char *)malloc((size + 1) * sizeof(char));
  
  rev[0] = '\0';

  for (int i = size - 1; i >= 0; i--) {
    strncat(rev, &str[i], 1);
  }

  return rev;
}

int is_operator(const char * c) {
  switch (*c) {
    case '+':
    case '-':
    case '*':
    case '/':
      return 1;
    default:
      return 0;
  }
}

int precedence(const char * c) {
  switch (*c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

// -------- Linked List Utils -----------

void expression_push(Expression * exp, char t) {
  LNode * node = (LNode *)malloc(sizeof(LNode));
  node->next = exp->head;
  node->term = t;
  exp->head = node;
  exp->size++;
}

char expression_get_term(Expression * exp, int index) {
  if (index >= exp->size) {
    perror("Index out of bounds");
    exit(EXIT_FAILURE);
  }

  LNode * node = exp->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node->term;
}

char expression_pop(Expression * exp) {
  if (exp->size == 0) {
    perror("Cannot pop from empty expression");
    exit(EXIT_FAILURE);
  }

  LNode * node = exp->head;
  exp->head = node->next;
  char t = node->term;
  free(node);
  exp->size--;
  return t;
}

char expression_pop_last(Expression * exp) {
  if (exp->size == 0) {
    perror("Cannot pop from empty expression");
    exit(EXIT_FAILURE);
  }

  LNode * node = exp->head;
  LNode * prev = NULL;
  while (node->next != NULL) {
    prev = node;
    node = node->next;
  }

  char t = node->term;
  free(node);
  exp->size--;

  if (prev == NULL) {
    exp->head = NULL;
  } else {
    prev->next = NULL;
  }

  return t;
}

// -------- Expression --------

Expression * expression_create_infix(const char * exp) {
  Expression * e = (Expression *)malloc(sizeof(Expression));
  e->head = NULL;
  e->size = 0;
  e->type = INFIX;

  for (int i = strlen(exp) - 1; i >= 0; i--) {
    expression_push(e, exp[i]);
  }

  return e;
}

void expression_convert_to_prefix(Expression * exp) {
  /// (a+b)*c -> ba+* -> *+ab

  if (exp->type == PREFIX) {
    return;
  }

  Stack * stack = create_stack();  // Operands stack
  Stack * output = create_stack(); // Output stack
  Stack * aux = create_stack();    // Aux stack

  while (exp->size > 0) {
    // Allocating term
    char * t = (char *)malloc(sizeof(char) * 2);
    t[0] = expression_pop_last(exp);
    t[1] = '\0';

    // Checking for operands
    if (isdigit(t[0])) {
      push(output, (void *)t);
      continue;
    }

    // Checking for operators
    if (is_operator(t)) {
      while (
        stack->size > 0 &&
        is_operator((char *)peek(stack)) &&
        precedence((char *)peek(stack)) >= precedence(t)
      ) {
        push(output, pop(stack));
      }
      push(stack, (void *)t);
      continue;
    }

    if (t[0] == ')') {
      push(stack, (void *)t);
      continue;
    }

    if (t[0] == '(') {
      while (
        stack->size > 0 &&
        *(char *)peek(stack) != ')'
      ) {
        push(output, pop(stack));
      }
      pop(stack); // Remove '('
      continue;
    }
  }

  // Pushing remaining operators to output stack
  while (stack->size > 0) {
    push(output, pop(stack));
  }

  // Reversing output stack to get the correct prefix expression
  while (output->size > 0) {
    push(aux, pop(output));
  }

  // Building the final expression
  while (aux->size > 0) {
    expression_push(exp, *(char *)pop(aux));
  }

  exp->type = PREFIX;

  delete_stack(aux);
  delete_stack(output);
  delete_stack(stack);
}

void expression_destroy(Expression * exp) {
  LNode * node = exp->head;
  while (node != NULL) {
    LNode * next = node->next;
    free(node);
    node = next;
  }
  free(exp);
}

void expression_print(Expression * exp) {
  LNode * node = exp->head;
  while (node != NULL) {
    printf("%c", node->term);
    node = node->next;
  }
  printf("\n");
}