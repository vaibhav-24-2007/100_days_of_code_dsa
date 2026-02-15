#include <stdio.h>

int main()
{
    int m,n,i,j;
    int a[100][100];
    int row[100]={0};
    int col[100]={0};

    printf("enter rows and cols: ");
    scanf("%d%d",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(row[i]==1 || col[j]==1)
            {
                a[i][j]=0;
            }
        }
    }

    printf("result matrix:\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
