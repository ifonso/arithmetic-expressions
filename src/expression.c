#include "expression.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int is_operator(char * c) {
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

int precedence(char * c) {
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

char * infix_to_prefix(char * exp) {
  return NULL;
}

// -------- Operations --------
