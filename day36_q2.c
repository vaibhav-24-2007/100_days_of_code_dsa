#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
public:
    vector<int> dq;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        dq.resize(k);
        front = -1;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        dq[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        dq[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (size == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (size == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque obj(3);

    cout << obj.insertLast(1) << endl;   
    cout << obj.insertLast(2) << endl;   
    cout << obj.insertFront(3) << endl;  
    cout << obj.insertFront(4) << endl;  
    cout << obj.getRear() << endl;       
    cout << obj.isFull() << endl;        
    cout << obj.deleteLast() << endl;    
    cout << obj.insertFront(4) << endl;  
    cout << obj.getFront() << endl;      

    return 0;
}
