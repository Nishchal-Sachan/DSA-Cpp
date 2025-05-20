#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Function to find first negative integer in every window of size k
vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int> dq;        // Stores indices of negative numbers
    vector<int> ans;

    // Process first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // Add result for first window
    if (!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process remaining windows
    for (int i = k; i < arr.size(); i++) {
        // Remove elements out of this window
        if (!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }

        // Add current element if it is negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // Append first negative number for this window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

// Main function
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> result = firstNegInt(arr, k);

    cout << "First negative integers in each window of size " << k << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
