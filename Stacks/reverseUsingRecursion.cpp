#include <bits/stdc++.h>
using namespace std;

// Function to push an element at the bottom of a stack
void solve(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

// Function to reverse the stack
void reverseStack(stack<int>& stack) {
    if (stack.empty()) {
        return;
    }

    int n = stack.top();
    stack.pop();

    reverseStack(stack);
    pushAtBottom(stack, n);
}

// Function to print stack from top to bottom
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;

    // Push initial elements
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Original Stack (Top to Bottom): ";
    printStack(myStack);

    // Reverse the stack
    reverseStack(myStack);

    cout << "Reversed Stack (Top to Bottom): ";
    printStack(myStack);

    return 0;
}
