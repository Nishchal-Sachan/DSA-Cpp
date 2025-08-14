#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find k-th smallest element
    int kthSmallest(vector<int> &arr, int k) {
        // Max Heap to store smallest k elements
        priority_queue<int> maxHeap;

        for (int i = 0; i < arr.size(); i++) {
            // Push elements until heap size is k
            if (maxHeap.size() < k) {
                maxHeap.push(arr[i]);
            }
            // If current element is smaller than heap's top, replace top
            else if (arr[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        // Top element is the k-th smallest
        return maxHeap.top();
    }
};

// Driver code
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution sol;
    cout << "✅ The " << k << "-th smallest element is: " << sol.kthSmallest(arr, k) << endl;

    return 0;
}
