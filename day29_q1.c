#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* nn = (Node*)malloc(sizeof(Node));
    if (nn == NULL) return NULL;
    nn->data = data;
    nn->next = NULL;
    return nn;
}

void append(Node** head, Node** tail, int data) {
    Node* nn = createNode(data);
    if (*head == NULL) {
        *head = nn;
        *tail = nn;
    } else {
        (*tail)->next = nn;
        *tail = nn;
    }
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL) printf(" ");
        cur = cur->next;
    }
}

Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    tail->next = head;

    int stepsToNewTail = len - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        append(&head, &tail, x);
    }

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    Node* cur = head;
    while (cur != NULL) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    return 0;
}
