# Expression Tree Assignment

## Title
Implementation and Evaluation of an Expression Tree Using Postfix Expression

## Given Postfix Expression
8 3 2 * + 6 2 / -

## Objective
To implement an Expression Tree using the given postfix expression and evaluate the expression using:

1. Stack-based postfix evaluation
2. Expression Tree evaluation

## Expression Tree

The expression tree represents:

((8 + (3 * 2)) - (6 / 2))

## Tree Traversals

### Inorder
((8 + (3 * 2)) - (6 / 2))

### Preorder
- + 8 * 3 2 / 6 2

### Postorder
8 3 2 * + 6 2 / -

## Result

Stack-Based Postfix Evaluation = 11

Expression Tree Evaluation = 11

## Complexity

### Stack-Based Postfix Evaluation
Time Complexity: O(n)
Space Complexity: O(n)

### Expression Tree
Tree Construction: O(n)
Tree Evaluation: O(n)
Space Complexity: O(n)

## Comparison

The stack-based method directly evaluates the postfix expression.

The Expression Tree stores the structure of the expression and allows
different traversals and access to sub-expressions.

## Files Included

- expression_tree.c – C source code
- input.txt – Input postfix expression
- output.txt – Program output
- complexity_analysis.txt – Complexity analysis
- comparison_table.txt – Comparison of both approaches
- conclusion.txt – Final conclusion

## Final Result

The given expression evaluates to:

11
