#include <bits/stdc++.h>
using namespace std;

// Function to reverse the first k elements of a queue
queue<int> reverseElements(queue<int> q, int k) {
    stack<int> s;

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue elements from stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements to the back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    int n, k;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    if (k > n || k < 0) {
        cout << "Invalid value of k. It should be between 0 and " << n << ".\n";
        return 0;
    }

    queue<int> result = reverseElements(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
