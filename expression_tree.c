#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[50];
int top = -1;

void push(struct Node *node) {
    stack[++top] = node;
}

struct Node *pop() {
    return stack[top--];
}

struct Node *createNode(char data) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        if (root->left != NULL)
            printf("(");

        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);

        if (root->right != NULL)
            printf(")");
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int evaluate(struct Node *root) {
    int left, right;

    if (isdigit(root->data))
        return root->data - '0';

    left = evaluate(root->left);
    right = evaluate(root->right);

    switch (root->data) {
        case '+':
            return left + right;

        case '-':
            return left - right;

        case '*':
            return left * right;

        case '/':
            return left / right;
    }

    return 0;
}

int main() {
    char postfix[] = "832*+62/-";

    int i;
    struct Node *root;

    for (i = 0; postfix[i] != '\0'; i++) {

        if (isdigit(postfix[i])) {
            push(createNode(postfix[i]));
        }
        else {
            struct Node *node = createNode(postfix[i]);

            node->right = pop();
            node->left = pop();

            push(node);
        }
    }

    root = pop();

    printf("Expression Tree Traversals:\n");

    printf("Inorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n\nExpression Tree Evaluation = %d\n",
           evaluate(root));

    return 0;
}
