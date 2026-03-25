#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

struct Pair {
    int value;
    int freq;
};

struct Pair heap[MAX];
int heapSize = 0;

void swap(struct Pair *a, struct Pair *b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].freq > heap[i].freq) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].freq < heap[smallest].freq)
        smallest = left;

    if (right < heapSize && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insertHeap(int value, int freq) {
    heap[heapSize].value = value;
    heap[heapSize].freq = freq;
    heapifyUp(heapSize);
    heapSize++;
}

void removeMin() {
    if (heapSize == 0) return;
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int main() {
    // Vaibhav Maheshwari
    // SAP ID ############

    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
                visited[j] = 1;
            }
        }

        insertHeap(nums[i], count);

        if (heapSize > k) {
            removeMin();
        }
    }

    while (heapSize > 0) {
        printf("%d ", heap[0].value);
        removeMin();
    }

    return 0;
}
