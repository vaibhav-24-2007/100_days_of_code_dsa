#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;
int k;

/* swap */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* heapify up */
void heapify_up(int i) {
    while(i > 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

/* heapify down */
void heapify_down(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

/* insert */
void insert(int val) {
    heap[size] = val;
    size++;
    heapify_up(size - 1);
}

/* remove min */
void remove_min() {
    heap[0] = heap[size - 1];
    size--;
    heapify_down(0);
}

/* KthLargest add */
int add(int val) {
    insert(val);

    if(size > k) {
        remove_min();
    }

    return heap[0];   // kth largest
}

int main() {
    // Vaibhav Maheshwari
    // SAP ID: ############

    int n;
    scanf("%d %d", &k, &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
        if(size > k) remove_min();
    }

    int q;
    scanf("%d", &q);

    while(q--) {
        int val;
        scanf("%d", &val);
        printf("%d\n", add(val));
    }

    return 0;
}
