#ifndef SEM3_DSA_C_EVAL_H
#define SEM3_DSA_C_EVAL_H

// supports chars (in order): ^ / * + -
// return weight of operator

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
void infixToPostfix(const char infix[], char postfix[]);

#endif  // SEM3_DSA_C_EVAL_H
