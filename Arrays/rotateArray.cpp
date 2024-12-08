#include <iostream>
#include <vector>
using namespace std;

// Function to rotate an array
vector<int> rotateArray(vector<int> arr, int k) {
    vector<int> ans;
    k = k % arr.size(); // Handle cases where k > size of array
    for (int i = k; i < arr.size(); i++) {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < k; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}

// Main function
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k (number of positions to rotate): ";
    cin >> k;

    vector<int> rotatedArray = rotateArray(arr, k);

    cout << "Rotated Array: ";
    for (int i = 0; i < rotatedArray.size(); i++) {
        cout << rotatedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
