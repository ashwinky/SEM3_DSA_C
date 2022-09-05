#include "eval.h"

#include <stdio.h>
#include <string.h>

#include "utils.h"

TEST("eval", {
  UNIT("simple expression", {
    char infix[] = "A+B";
    char postfix[4];

    char result[] = "AB+";

    infixToPostfix(infix, postfix);

    for (int i = 0; i < strlen(postfix); i++) {
      ASSERT(postfix[i], result[i]);
    }
  });

  UNIT("complex expression", {
    char infix[] = "A+B*C-(D/E^F)*G";
    char postfix[20];

    char result[] = "ABC*+DEF^/G*-";

    infixToPostfix(infix, postfix);

    for (int i = 0; i < strlen(postfix); i++) {
      ASSERT(postfix[i], result[i]);
    }
  });
})
