#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum cost of connecting all ropes
    int minCost(vector<int>& arr) {
        // Min-heap to always get the smallest two ropes
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Push all ropes into the min-heap
        for (auto i : arr) {
            minHeap.push(i);
        }

        int totalCost = 0;

        // Keep combining ropes until only one rope remains
        while (minHeap.size() > 1) {
            // Take out two smallest ropes
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();

            // Combine them
            int sum = a + b;
            totalCost += sum;

            // Push the combined rope back into heap
            minHeap.push(sum);
        }

        return totalCost;
    }
};

// Driver code
int main() {
    vector<int> ropes = {4, 3, 2, 6};

    Solution obj;
    int result = obj.minCost(ropes);

    cout << "Minimum cost to connect ropes: " << result << endl;
    return 0;
}
