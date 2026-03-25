#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct
{
    node **arr;
    int front;
    int rear;
} queue;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

queue *createQueue(int n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->arr = (node **)malloc(sizeof(node *) * n);
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(queue *q, node *temp)
{
    q->arr[q->rear++] = temp;
}

node *dequeue(queue *q)
{
    return q->arr[q->front++];
}

int isEmpty(queue *q)
{
    return q->front == q->rear;
}

node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
    {
        return NULL;
    }

    node *root = createNode(arr[0]);
    queue *q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (i < n && !isEmpty(q))
    {
        node *current = dequeue(q);

        if (i < n && arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    node *root = buildTree(arr, n);
    printf("%d", height(root));

    return 0;
}
