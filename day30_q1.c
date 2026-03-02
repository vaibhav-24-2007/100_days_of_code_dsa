#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int c, int e) {
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->coeff = c;
    nn->exp = e;
    nn->next = NULL;
    return nn;
}

void insert(Node** head, int c, int e) {
    Node* nn = createNode(c, e);

    if (*head == NULL || (*head)->exp < e) {
        nn->next = *head;
        *head = nn;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;
}

void printPoly(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* t = head;
        head = head->next;
        free(t);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        insert(&head, c, e);
    }

    printPoly(head);
    freeList(head);

    return 0;
}
