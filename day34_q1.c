#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop() {
    if (top == NULL) {
        printf("stack underflow");
        exit(1);
    }
    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int no. = 0;
            while (isdigit(exp[i])) {
                no. = no. * 10 + (exp[i] - '0');
                i++;
            }
            push(no.);
        } else {
            int b = pop();
            int a = pop();
            int result;

            switch (exp[i]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                default:
                    printf("invalid operator");
                    exit(1);
            }

            push(result);
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("enter postfix expression ");
    fgets(exp, sizeof(exp), stdin);

    int ans = evaluatePostfix(exp);

    printf("result %d", ans);

    return 0;
}
