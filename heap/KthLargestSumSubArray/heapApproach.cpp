#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    // Min-heap to store top k largest sums
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];

            if (minHeap.size() < k) {
                minHeap.push(sum);
            } 
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    return minHeap.top(); // k-th largest sum
}

int main() {
    vector<int> arr = {3, -2, 5};
    int k = 2;
    cout << "K-th largest subarray sum: " << getKthLargest(arr, k) << endl;
    return 0;
}
