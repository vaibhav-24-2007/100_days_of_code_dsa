#include <stdio.h>

int main()
{
    int n;
    printf("enter size: ");
    scanf("%d", &n);

    int a[n][n];
    int i, j, temp;

    printf("enter elements:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // transpose
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // reverse each row
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n / 2; j++)
        {
            temp = a[i][j];
            a[i][j] = a[i][n - j - 1];
            a[i][n - j - 1] = temp;
        }
    }

    printf("rotated matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
