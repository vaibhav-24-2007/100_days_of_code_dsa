#include <stdio.h>

int main()
{
    int n, i, j;
    int a[10][10];
    int sum = 0;

    printf("enter order of square matrix: ");
    scanf("%d", &n);

    printf("enter elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        sum = sum + a[i][i];
    }

    printf("sum of primary diagonal = %d", sum);

    return 0;
}
