#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') {   // enqueue
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else {              // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
