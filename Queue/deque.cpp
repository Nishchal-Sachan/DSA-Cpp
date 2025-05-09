#include <iostream>
using namespace std;

// Include your Deque class definition here
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size=n;
        arr  = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0 && rear!=(size-1)){
            front =size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front =rear=0;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(front ==-1){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front =rear=-1;
        }else if(front ==size-1){
            front =0;
        }else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front==-1){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front == rear){
            front = rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front ==-1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front==0 && rear== size-1)|| (front!=0&&(rear==(front-1)%(size-1)))){
            return true;
        }
        return false;
    }
};

int main() {
    Deque dq(5); // Deque of size 5

    // Push elements at rear
    cout << "Push Rear 10: " << dq.pushRear(10) << endl;
    cout << "Push Rear 20: " << dq.pushRear(20) << endl;

    // Push elements at front
    cout << "Push Front 5: " << dq.pushFront(5) << endl;
    cout << "Push Front 3: " << dq.pushFront(3) << endl;

    // Current front and rear
    cout << "Front Element: " << dq.getFront() << endl;
    cout << "Rear Element: " << dq.getRear() << endl;

    // Pop front and rear
    cout << "Pop Front: " << dq.popFront() << endl;
    cout << "Pop Rear: " << dq.popRear() << endl;

    // Push more to check circularity
    cout << "Push Rear 25: " << dq.pushRear(25) << endl;
    cout << "Push Front 1: " << dq.pushFront(1) << endl;

    // Check if full
    cout << "Is Full: " << dq.isFull() << endl;

    // Print final state
    cout << "Front Element: " << dq.getFront() << endl;
    cout << "Rear Element: " << dq.getRear() << endl;

    return 0;
}
