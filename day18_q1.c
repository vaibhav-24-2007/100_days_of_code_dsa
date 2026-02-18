#include <stdio.h>

int main()
{
    int arr[100], n, k, i, temp[100];

    printf("Enter no. of elements ");
    scanf("%d", &n);

    printf("Enter elements ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k value ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    for(i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    printf("Rotated array ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
