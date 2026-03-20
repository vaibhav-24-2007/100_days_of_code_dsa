#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// enqueue
void enqueue(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("memory allocation failed");
        return;
    }

    newnode->data = value;

    if (front == NULL) {
        front = rear = newnode;
        rear->next = front;  // circular link
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  // maintain circular
    }
}

// dequeue
void dequeue() {
    if (front == NULL) return;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct node *temp = front;
        front = front->next;
        rear->next = front;  // maintain circular
        free(temp);
    }
}

// display
void display() {
    if (front == NULL) return;

    struct node *temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, x, m;

    scanf("%d", &n);

    // enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // perform m dequeues
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // print remaining queue
    display();

    return 0;
}
