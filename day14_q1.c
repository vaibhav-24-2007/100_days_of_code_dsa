#include <stdio.h>

int main()
{
    int n;
    printf("enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n];
    int i, j;
    int flag = 1;

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
        for(j = 0; j < n; j++)
        {
            if(i == j && a[i][j] != 1)
            {
                flag = 0;
                break;
            }
            if(i != j && a[i][j] != 0)
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
        printf("it is identity matrix");
    else
        printf("it is not identity matrix");

    return 0;
}
