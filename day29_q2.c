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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* head = NULL;
    Node* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        append(&head, &tail, sum % 10);
    }

    return head;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL) printf(" ");
        cur = cur->next;
    }
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* nxt = head->next;
        free(head);
        head = nxt;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    Node* l1 = NULL;
    Node* t1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        append(&l1, &t1, x);
    }

    scanf("%d", &m);

    Node* l2 = NULL;
    Node* t2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        append(&l2, &t2, x);
    }

    Node* ans = addTwoNumbers(l1, l2);
    printList(ans);

    freeList(l1);
    freeList(l2);
    freeList(ans);

    return 0;
}
