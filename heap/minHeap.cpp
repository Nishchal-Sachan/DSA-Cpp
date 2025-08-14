#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index 'i' in a min heap
void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;            // Assume the root is the smallest
    int left = 2 * i + 1;         // Left child index
    int right = 2 * i + 2;        // Right child index

    // Check if left child exists and is smaller than the root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // Check if right child exists and is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If the smallest is not root, swap and recursively heapify
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min heap from an unsorted array
vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();

    // Start heapifying from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

// Driver function to test the heap build
int main() {
    vector<int> arr = {9, 4, 7, 1, -2, 6, 5};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    buildMinHeap(arr);

    cout << "Min Heap: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
