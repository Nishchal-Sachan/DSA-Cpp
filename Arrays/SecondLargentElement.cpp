#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in the array
int findSecondLargest(int n, vector<int>& arr) {
    if (n < 2) return -1; // Not enough elements for a second largest

    int maxi = INT_MIN;
    int secMaxi = INT_MIN;

    for (int i : arr) {
        if (i > maxi) {
            secMaxi = maxi; // Update second largest
            maxi = i;       // Update largest
        } else if (i > secMaxi && i < maxi) {
            secMaxi = i;    // Update second largest if smaller than max
        }
    }

    // If no second largest element exists, return -1
    return (secMaxi == INT_MIN) ? -1 : secMaxi;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int secondLargest = findSecondLargest(n, arr);

    if (secondLargest == -1) {
        cout << "No second largest element exists." << endl;
    } else {
        cout << "The second largest element is: " << secondLargest << endl;
    }

    return 0;
}
