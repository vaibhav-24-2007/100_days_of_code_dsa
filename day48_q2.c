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

int isLeaf(node* temp)
{
    if(temp != NULL && temp->left == NULL && temp->right == NULL)
        return 1;
    return 0;
}

int sumLeftLeaves(node* root)
{
    if(root == NULL)
        return 0;

    int sum = 0;

    if(root->left && isLeaf(root->left))
        sum += root->left->data;

    sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);

    return sum;
}

int main()
{
    node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("%d", sumLeftLeaves(root));

    return 0;
}
