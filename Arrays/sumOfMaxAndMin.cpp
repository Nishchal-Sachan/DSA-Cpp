#include <bits/stdc++.h>
using namespace std;

int sumOfMaxMin(int arr[], int n) {
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (maxi < arr[i]) {
            maxi = arr[i];
        }
        if (mini > arr[i]) {
            mini = arr[i];
        }
    }
    return maxi + mini;
}

int main() {
    int n;

    // Input size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare the array
    int arr[n];

    // Input elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function and display the result
    int result = sumOfMaxMin(arr, n);
    cout << "The sum of the maximum and minimum elements is: " << result << endl;

    return 0;
}
