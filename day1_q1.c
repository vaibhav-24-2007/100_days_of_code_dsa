#include <stdio.h>

int main()
{
    int a[100];
    int n;
    int x;
    int pos;
    int i;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter element to insert: ");
    scanf("%d", &x);

    printf("enter position (1-based): ");
    scanf("%d", &pos);

    for(i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;
    n++;

    printf("array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int a[100];
    int n;
    int x;
    int pos;
    int i;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter element to insert: ");
    scanf("%d", &x);

    printf("enter position (1-based): ");
    scanf("%d", &pos);

    for(i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;
    n++;

    printf("array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
