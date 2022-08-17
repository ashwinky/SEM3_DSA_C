#include <stdio.h>

#include "eval.h"

int main() {
  // char infix[] = "A+(B*C-(D/E^F)*G)*H";
  char infix[50] = "";
  char postfix[50] = "";

  printf("Enter infix: ");
  scanf("%50[^\n]s", infix);
  printf("< '%s'\n", infix);

  infixToPostfix(infix, postfix);

  printf("> '%s'\n", postfix);

  return 0;
}
