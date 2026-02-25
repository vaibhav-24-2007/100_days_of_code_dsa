#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeElements(struct Node* head, int val) {
    struct Node *temp;

    // Remove matching nodes from beginning
    while(head != NULL && head->data == val) {
        temp = head;
        head = head->next;
        free(temp);
    }

    struct Node *current = head;
    
    while(current != NULL && current->next != NULL) {
        if(current->next->data == val) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    int n, val, i, value;
    struct Node *head = NULL, *newNode, *temp;

    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    scanf("%d", &val);

    head = removeElements(head, val);

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
