#include <stdio.h>

int main()
{

    int nums[100];
    int n;
    int target;
    int i;
    int j;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("enter target: ");
    scanf("%d
