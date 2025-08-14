#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Heapify function to maintain Max Heap property
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Find the largest among root, left, and right
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Merge two heaps and build a single max heap
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b) {
        // Step 1: Merge arrays
        vector<int> merged = a;
        merged.insert(merged.end(), b.begin(), b.end());

        // Step 2: Build Max Heap from merged array
        int n = merged.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(merged, n, i);
        }

        return merged;
    }
};

// --------------------- MAIN FUNCTION ---------------------
int main() {
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    Solution sol;
    vector<int> mergedHeap = sol.mergeHeaps(heap1, heap2);

    cout << "Merged Max Heap: ";
    for (int val : mergedHeap) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
