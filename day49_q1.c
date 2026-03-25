#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* create(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int val)
{
    if(root == NULL)
        return create(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n, x;
    scanf("%d", &n);

    node* root = NULL;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}
