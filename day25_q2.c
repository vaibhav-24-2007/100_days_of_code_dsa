#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *detectCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    // Step 1: Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            // Step 2: Find starting node of cycle
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Start of cycle
        }
    }

    return NULL;  // No cycle
}
