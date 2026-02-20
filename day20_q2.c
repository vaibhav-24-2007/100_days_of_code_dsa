#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);

    qsort(nums, n, sizeof(int), cmp);

    for(int i = 0; i < n - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0)
            {
                printf("%d %d %d\n", nums[i], nums[left], nums[right]);

                int a = nums[left], b = nums[right];
                while(left < right && nums[left] == a) left++;
                while(left < right && nums[right] == b) right--;
            }
            else if(sum < 0)
                left++;
            else
                right--;
        }
    }

    free(nums);
    return 0;
}
