#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to check cycle
bool hasCycle(struct Node* head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if(slow == fast) {
            return true;            // cycle detected
        }
    }

    return false;                   // no cycle
}

int main() {
    int n, pos;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *cycleNode = NULL;
    int value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if(i == 0)
            cycleNode = head;   // just storing first node example
    }

    scanf("%d", &pos);

    // If pos != -1, create cycle
    if(pos != -1) {
        struct Node* connectNode = head;
        for(int i = 0; i < pos; i++)
            connectNode = connectNode->next;

        temp->next = connectNode;
    }

    if(hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
