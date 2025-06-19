#include <bits/stdc++.h>
using namespace std;

// Function for insertion sort
void insertionSort(int n, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        int curr = arr[i], prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    // Input array size
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting the array using insertion sort
    insertionSort(n, arr);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
