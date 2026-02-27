#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

bool removeCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle found

            slow = head;
            struct Node* prev = NULL;

            // Find starting point of cycle
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Break cycle
            prev->next = NULL;

            return true;
        }
    }

    return false; // No cycle
}

int main() {
    int n, val, pos;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    // Creating cycle manually (for testing)
    scanf("%d", &pos);  
    if (pos >= 0) {
        struct Node* temp = head;
        struct Node* cycleNode = NULL;
        int index = 0;

        while (temp->next != NULL) {
            if (index == pos)
                cycleNode = temp;
            temp = temp->next;
            index++;
        }
        temp->next = cycleNode;  // create cycle
    }

    if (removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}
