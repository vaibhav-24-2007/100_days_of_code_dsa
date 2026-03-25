#include <stdio.h>

#define MAX 100000

void maxSlidingWindow(int nums[], int n, int k) {
    int dq[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        while (front <= rear && dq[front] <= i - k) {
            front++;
        }

        while (front <= rear && nums[dq[rear]] < nums[i]) {
            rear--;
        }

        dq[++rear] = i;

        if (i >= k - 1) {
            printf("%d ", nums[dq[front]]);
        }
    }
}

int main() {
    // Vaibhav Maheshwari
    // SAP ID: ############

    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    maxSlidingWindow(nums, n, k);

    return 0;
}
