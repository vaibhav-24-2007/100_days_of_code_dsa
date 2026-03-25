#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, i, x;
    scanf("%d", &n);

    // input queue
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // step 1: queue -> stack
    while (front <= rear) {
        push(dequeue());
    }

    // step 2: stack -> queue
    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }

    // print reversed queue
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
