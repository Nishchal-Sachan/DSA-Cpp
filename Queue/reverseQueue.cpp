#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> s;

        // Push all elements from queue to stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }

        // Push all elements back to queue from stack
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        return q;
    }
};

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    Solution sol;
    queue<int> reversedQ = sol.reverseQueue(q);

    cout << "Reversed queue: ";
    while (!reversedQ.empty()) {
        cout << reversedQ.front() << " ";
        reversedQ.pop();
    }
    cout << endl;

    return 0;
}
