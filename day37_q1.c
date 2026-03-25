#include <stdio.h>

int main() {
    // Vaibhav Maheshwari
    // SAP ID: ############

    int n;
    scanf("%d", &n);

    int pq[1000];
    int size = 0;

    for(int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if(op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            pq[size] = x;
            size++;
        }

        else if(op[0] == 'd') {   // delete
            if(size == 0) {
                printf("-1\n");
            } else {
                int minIndex = 0;
                for(int j = 1; j < size; j++) {
                    if(pq[j] < pq[minIndex]) {
                        minIndex = j;
                    }
                }

                printf("%d\n", pq[minIndex]);

                for(int j = minIndex; j < size - 1; j++) {
                    pq[j] = pq[j + 1];
                }
                size--;
            }
        }

        else if(op[0] == 'p') {   // peek
            if(size == 0) {
                printf("-1\n");
            } else {
                int minIndex = 0;
                for(int j = 1; j < size; j++) {
                    if(pq[j] < pq[minIndex]) {
                        minIndex = j;
                    }
                }

                printf("%d\n", pq[minIndex]);
            }
        }
    }

    return 0;
}
