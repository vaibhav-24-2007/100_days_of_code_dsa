#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// create node
struct node* newNode(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// queue
struct node* queue[100];
int front = 0, rear = -1;

void enqueue(struct node* x) {
    queue[++rear] = x;
}

struct node* dequeue() {
    return queue[front++];
}

// build tree from level order
struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// max depth
int maxDepth(struct node* root) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    printf("%d\n", maxDepth(root));

    return 0;
}
