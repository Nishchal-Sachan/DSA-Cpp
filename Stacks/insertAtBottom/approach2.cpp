#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int>s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return st;
    }
};

void printStack(stack<int> st) {
    // print from top to bottom
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Sample input
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    int x = 99;  // Element to insert at bottom

    Solution obj;
    stack<int> result = obj.insertAtBottom(st, x);

    cout << "Stack after inserting " << x << " at bottom:\n";
    printStack(result);  // Top to bottom
    return 0;
}
