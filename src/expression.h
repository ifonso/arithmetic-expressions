#ifndef EXPRESSION_H_
#define EXPRESSION_H_

// --------------------- Function declarations ---------------------

char * shunting_yard(char * infix);

int is_operator(const char * c);
int precedence(const char * c);

#endif /* EXPRESSION_H_ */