#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if the array is sorted and rotated
bool check(vector<int>& arr) {
    int n = arr.size();
    int count = 0;  // To count the number of points where the order breaks

    // Traverse through the array and count the number of drops
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            count++;
        }
    }

    // If there is more than one drop, it's not a rotated sorted array
    if (count > 1) {
        return false;
    }

    // If there's no drop, the array is already sorted in ascending order
    // If there's one drop, check if the last element is <= the first element (rotation)
    return (count == 0 || arr[n - 1] <= arr[0]);
}

int main() {
    vector<int> arr = {3, 6, 10, 1, 8, 9, 9, 8, 9};  // Test case
    cout << check(arr);  // Expected output: false
}

