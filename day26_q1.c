#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    char your_name[] = "vaibhav maheshwari";
    char your_sapid[] = "590022236";

    printf("Name %s SAP-ID %s\n", your_name, your_sapid);

    int n, i, value;

    scanf("%d", &n);

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
