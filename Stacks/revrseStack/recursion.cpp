#include <bits/stdc++.h> 
using namespace std;

void insertSorted(stack<int>& s, int n) {
    if (s.empty() || s.top() <= n) {
        s.push(n);
        return;
    }

    int x = s.top();
    s.pop();
    insertSorted(s, n);
    s.push(x);  // <- restore the popped element
}

void sortStack(stack<int>& stack) {
    if (stack.empty()) {
        return;
    }

    int n = stack.top();
    stack.pop();

    sortStack(stack);

    insertSorted(stack, n);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original Stack (Top to Bottom): ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack (Top to Bottom): ";
    printStack(s);

    return 0;
}
