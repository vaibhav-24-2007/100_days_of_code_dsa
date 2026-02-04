#include <stdio.h>

int main()
{
    int n;
    int pos;
    int i;
    int arr[100];

    printf("enter no. of elements: ");
    scanf("%d", &n);

    printf("enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter position to delete (1-based): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("invalid position");
    }
    else
    {
        for(i = pos - 1; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n = n - 1;

        printf("array after deletion:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
