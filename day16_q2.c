#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    int temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n, k, i;

    printf("enter no. of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("enter k: ");
    scanf("%d", &k);

    k = k % n;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);

    printf("array after rotation:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
