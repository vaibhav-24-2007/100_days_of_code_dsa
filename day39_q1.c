#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

/* swap */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* heapify up */
void heapify_up(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
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
void insert(int x) {
    heap[size] = x;
    size++;
    heapify_up(size - 1);
}

/* extract min */
void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapify_down(0);
}

/* peek */
void peek() {
    if(size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}

int main() {
    // Vaibhav Maheshwari
    // SAP ID: ############

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'e') {   // extractMin
            extractMin();
        }
        else if(op[0] == 'p') {   // peek
            peek();
        }
    }

    return 0;
}
