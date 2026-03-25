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

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int depth(node* root)
{
    if(root == NULL)
        return 0;

    int l = depth(root->left);
    int r = depth(root->right);

    return max(l, r) + 1;
}

int main()
{
    node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("%d", depth(root));

    return 0;
}
