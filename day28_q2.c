#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isPalindrome(struct Node* head) {
    int arr[1000];
    int i = 0, j;
    struct Node* temp = head;

    // Store elements in array
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    // Compare from start and end
    for (j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1]) {
            return 0;   // Not Palindrome
        }
    }

    return 1;   // Palindrome
}

int main() {
    int n, value, i;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if (isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}
