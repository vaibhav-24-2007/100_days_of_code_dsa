#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix_sum = 0;
    int count = 0;

    // Since constraints are not given, using simple frequency array logic
    // assuming prefix sums range safely within -100000 to 100000

    int freq[200001] = {0};
    int offset = 100000;

    freq[offset] = 1;   // prefix sum 0 occurs once initially

    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];

        if(freq[prefix_sum + offset] > 0)
            count += freq[prefix_sum + offset];

        freq[prefix_sum + offset]++;
    }

    printf("%d", count);

    return 0;
}
