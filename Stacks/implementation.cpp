#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push
    void push(int d)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = d;
        }
        else
        {
            cout << "Stack overflow!" << endl;
        }
    }

    // Pop
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow!" << endl;
        }
    }

    // Peek
    int peek()
    {
        if (top > 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty";
            return -1;
        }
    }

    // Empty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main() {
    Stack s(5); // create a stack of size 5

    // Push elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Peek at the top element
    cout << "Top element is: " << s.peek() << endl;

    // Pop an element
    s.pop();

    // Peek again
    cout << "Top element after pop is: " << s.peek() << endl;

    // Check if stack is empty
    if (s.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    // Pop all elements
    s.pop();
    s.pop();
    s.pop(); // extra pop to test underflow

    return 0;
}
