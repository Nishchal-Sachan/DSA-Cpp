#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int size;
    int qfront;
    int qrear;

public:
    Queue() {
        size = 1001;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    bool isEmpty() {
        return qfront == qrear;
    }

    void enqueue(int data) {
        if (qrear == size) {
            cout << "Queue is full!!" << endl;
        } else {
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        if (qfront == qrear) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == qrear) {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == qrear) {
            return -1;
        } else {
            return arr[qfront];
        }
    }
};

// Main function to demonstrate usage
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    // Trying to dequeue from empty queue
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}
