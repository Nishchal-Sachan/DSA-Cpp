#include <iostream>
#include <stack>
using namespace std;

class Solution {
  private:
    void solve(stack<int>& s, int count, int size) {
        if (count == size / 2) {
            s.pop();
            return;
        }
        int num = s.top();
        s.pop();
        solve(s, count + 1, size);
        s.push(num);
    }

  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int count = 0;
        int size = s.size();
        solve(s, count, size);
    }
};

int main() {
    stack<int> s;

    // Example input
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    Solution obj;
    obj.deleteMid(s);

    // Printing stack after deleting middle
    cout << "Stack after deleting middle element:" << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
