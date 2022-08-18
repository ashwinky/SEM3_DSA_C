#include "eval.h"

#include <stdio.h>

#include "utils.h"

void push(char stack[], int size, char value) { stack[size] = value; }

char pop(char stack[], int size) {
  char value = stack[size - 1];
  stack[size - 1] = '\0';
  return value;
}

// Returns the precedence weight of the operator.
int precedence(char c) {
  switch (c) {
    case '^':
      return 5;
    case '/':
      return 4;
    case '*':
      return 3;
    case '+':
      return 2;
    case '-':
      return 1;
    default:
      return 0;
  }
}

/*
 * Infix to Postfix
 * This algorithm will convert the infix expression to postfix expression.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * Example: A+(B*C-(D/E^F)*G)*H => ABC*DEF^/G*-H*
 *
 * @param infix - the infix expression
 * @param postfix - the postfix expression
 * @param dbg - whether to print debug messages
 */
void infixToPostfix(const char infix[], char postfix[]) {
  char stack[100] = "";  // stack for operators
  int size = 0;          // size of stack

  int i = 0;  // index of infix
  int j = 0;  // index of postfix

  char c;  // current char

  D(printf("| Char | Stack            | Postfix          |\n");)
  D(printf("| ---- | ---------------- | ---------------- |\n");)

  // iterate through infix expression
  while (infix[i] != '\0') {
    c = infix[i];  // get current char

    if (c == '(') {
      // if current char is '(',
      push(stack, size, c);  // push '(' to stack
      size++;
    } else if (c == ')') {
      // if current char is ')',
      // pop all operators from stack until '(' is found
      while (stack[size - 1] != '(') {
        postfix[j] =
            pop(stack, size);  // pop operator from stack and add to postfix
        j++;
        size--;
      }
      // pop '(' from stack
      pop(stack, size);
      size--;
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
      // if current char is an operator,
      // pop all operators until stack is empty or current operator has lower
      // precedence than top of stack
      while (size > 0 && precedence(c) < precedence(stack[size - 1])) {
        postfix[j] =
            pop(stack, size);  // pop operator from stack and add to postfix
        j++;
        size--;
      }
      // push current operator to stack
      push(stack, size, c);
      size++;
    } else {
      // if current char is a number or variable,
      postfix[j] = c;  // add to postfix
      j++;
    }

    i++;  // go to next char

    D(printf("| %c    | %-16s | %-16s |\n", c, stack, postfix);)
  }

  // pop all operators from stack and add to postfix
  while (size > 0) {
    postfix[j] = pop(stack, size);
    j++;
    size--;
  }

  D(printf("| _EOF | %-16s | %-16s |\n", stack, postfix);)

  postfix[j] = '\0';
}
