#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int main()
{
    int n;
    printf("Enter no. of elements ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements ");
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int total = 0;

    int curMax = nums[0], maxSum = nums[0];
    int curMin = nums[0], minSum = nums[0];

    total = nums[0];

    for(int i = 1; i < n; i++)
    {
        total += nums[i];

        curMax = max(nums[i], curMax + nums[i]);
        maxSum = max(maxSum, curMax);

        curMin = min(nums[i], curMin + nums[i]);
        minSum = min(minSum, curMin);
    }

    if(maxSum < 0)
    {
        printf("%d\n", maxSum);
    }
    else
    {
        int circularMax = total - minSum;
        printf("%d\n", max(maxSum, circularMax));
    }

    return 0;
}
