#include <stdio.h>

int main()
{
    int your_no, i;

    char your_name[] = "vaibhav maheshwari";
    char your_sapid[] = "590022236";
    printf("Name %s SAP-ID %s\n", your_name, your_sapid);

    printf("enter no. of elements ");
    scanf("%d", &your_no);

    int nums[your_no];

    printf("enter elements ");
    for(i = 0; i < your_no; i++)
    {
        scanf("%d", &nums[i]);
    }

    int curr = nums[0];
    int best = nums[0];

    for(i = 1; i < your_no; i++)
    {
        if(curr + nums[i] > nums[i])
            curr = curr + nums[i];
        else
            curr = nums[i];

        if(curr > best)
            best = curr;
    }

    printf("largest subarray sum %d\n", best);

    return 0;
}
