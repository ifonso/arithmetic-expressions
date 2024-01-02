#include "expression.h"
#include "stack.h"
#include "AST.h"

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

char * shunting_yard(char * infix) {
  Stack * stack = create_stack();
  char * output = (char *)malloc(sizeof(char)*MAX_OUT_SIZE);
  output[0] = '\0';

  for (int i = 0; i < strlen(infix); i++) {

    if (isdigit(infix[i])) {
      strncat(output, &infix[i], 1);
      continue;
    }

    char * c = malloc(sizeof(char) * 2);
    c[0] = '\0';
    strncpy(c, &infix[i], 1);

    if (infix[i] == '(') {
      push(stack, (void *)c);

    } else if (infix[i] == ')') {
      while (
        stack->size > 0 && 
        *(char *)peek(stack) != '('
      ) {
        strcat(output, (char *)pop(stack));
      }
      // removing (
      pop(stack);

    } else {
      while(
        stack->size != 0 &&
        *(char *)peek(stack) != '(' &&
        precedence((char *)peek(stack)) >= precedence(c)
      ) {
        strcat(output, (char *)pop(stack)); 
      }

      push(stack, (void *)c);
    }
  }
  
  while (stack->size > 0) {
    strcat(output, (char *)pop(stack));
  }

  delete_stack(stack);

  return output;
}
