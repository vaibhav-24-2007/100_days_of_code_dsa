#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

/* check empty */
int empty() {
    return (front == -1);
}

/* size */
int size() {
    if(front == -1) return 0;
    if(rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

/* push front */
void push_front(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear + 1)) {
        return; // full
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    dq[front] = x;
}

/* push back */
void push_back(int x) {
    if((front == 0 && rear == MAX-1) || (front == rear + 1)) {
        return; // full
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    dq[rear] = x;
}

/* pop front */
void pop_front() {
    if(empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

/* pop back */
void pop_back() {
    if(empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

/* front element */
void get_front() {
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

/* back element */
void get_back() {
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

/* clear */
void clear() {
    front = rear = -1;
}

/* display */
void display() {
    if(empty()) {
        printf("empty\n");
        return;
    }

    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    // Vaibhav Maheshwari
    // SAP ID: ############

    int n;
    scanf("%d", &n);

    while(n--) {
        char op[20];
        scanf("%s", op);

        if(op[0]=='p' && op[5]=='f') { // push_front
            int x; scanf("%d",&x);
            push_front(x);
        }
        else if(op[0]=='p' && op[5]=='b') { // push_back
            int x; scanf("%d",&x);
            push_back(x);
        }
        else if(op[0]=='p' && op[4]=='f') { // pop_front
            pop_front();
        }
        else if(op[0]=='p' && op[4]=='b') { // pop_back
            pop_back();
        }
        else if(op[0]=='f') {
            get_front();
        }
        else if(op[0]=='b') {
            get_back();
        }
        else if(op[0]=='e') {
            printf("%d\n", empty());
        }
        else if(op[0]=='s') {
            printf("%d\n", size());
        }
        else if(op[0]=='c') {
            clear();
        }
        else if(op[0]=='d') {
            display();
        }
    }

    return 0;
}
