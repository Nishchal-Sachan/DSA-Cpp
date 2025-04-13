#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> & s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;

    // Pushing some elements into the stack
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    cout << "Original Stack (Top to Bottom): ";
    printStack(myStack);

    int x = 4; // Element to push at the bottom

    // Call the function
    myStack = pushAtBottom(myStack, x);

    cout << "Updated Stack after pushing " << x << " at the bottom: ";
    printStack(myStack);

    return 0;
}
