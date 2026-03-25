#include <stdio.h>

#define MAX 100000

int main() {
    // Vaibhav Maheshwari
    // SAP ID ############

    int n;
    scanf("%d", &n);

    int temp[n], ans[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
        ans[i] = 0;
    }

    int stack[MAX];
    int top = -1;

    for(int i = 0; i < n; i++) {
        while(top != -1 && temp[i] > temp[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
