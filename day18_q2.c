#include <stdio.h>

int main()
{
    int nums[100], answer[100];
    int n, i;

    printf("Enter no. of elements ");
    scanf("%d", &n);

    printf("Enter elements ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int prefix = 1;

    for(i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix = prefix * nums[i];
    }

    int suffix = 1;

    for(i = n - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * suffix;
        suffix = suffix * nums[i];
    }

    printf("Output array ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}
