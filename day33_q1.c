#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push
void push(char x) {
    stack[++top] = x;
}

// pop
char pop() {
    return stack[top--];
}

// precedence
int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("enter infix ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        // operand
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // opening bracket
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // closing bracket
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("postfix %s", postfix);

    return 0;
}
