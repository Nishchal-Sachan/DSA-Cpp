#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element in the array
int findPeakElement(vector<int>& arr) {
    // Handle edge case for the first element being a peak
    if (arr[0] > arr[1]) {
        return 0;
    }

    // Handle edge case for the last element being a peak
    if (arr[arr.size() - 1] > arr[arr.size() - 2]) {
        return arr.size() - 1;
    }

    // Iterate through the array and check for peak
    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i; // Return index of the peak element
        }
    }

    // If no peak element is found, return -1 (though not expected for valid inputs)
    return -1;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input validation
    if (n < 1) {
        cout << "Array must have at least one element!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the findPeakElement function
    int peakIndex = findPeakElement(arr);

    // Print the result
    if (peakIndex != -1) {
        cout << "Peak element found at index: " << peakIndex << endl;
        cout << "Peak element is: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak element found." << endl;
    }

    return 0;
}
