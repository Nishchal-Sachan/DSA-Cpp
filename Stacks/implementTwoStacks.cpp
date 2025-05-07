#include <iostream>
using namespace std;
class TwoStack
{
    int first;
    int second;
    int size;
    int *arr;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        this->size = s;
        arr = new int[s];
        first = -1;
        second = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (second - first > 1)
        {
            first++;
            arr[first] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (second - first > 1)
        {
            second--;
            arr[second] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (first >= 0)
        {
            int ans = arr[first];
            first--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (second < size)
        {
            int ans = arr[second];
            second++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    // Create a TwoStack object with size 10
    TwoStack ts(10);

    // Push elements into stack 1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements into stack 2
    ts.push2(100);
    ts.push2(90);
    ts.push2(80);

    // Pop elements from stack 1
    cout << "Popped from stack 1: " << ts.pop1() << endl; // 15
    cout << "Popped from stack 1: " << ts.pop1() << endl; // 10

    // Pop elements from stack 2
    cout << "Popped from stack 2: " << ts.pop2() << endl; // 80
    cout << "Popped from stack 2: " << ts.pop2() << endl; // 90

    // Try to pop more than pushed to test edge case
    cout << "Popped from stack 1: " << ts.pop1() << endl; // 5
    cout << "Popped from stack 1: " << ts.pop1() << endl; // -1 (empty)

    cout << "Popped from stack 2: " << ts.pop2() << endl; // 100
    cout << "Popped from stack 2: " << ts.pop2() << endl; // -1 (empty)

    return 0;
}
