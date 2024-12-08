#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Function to rotate an array by one position
vector<int> rotateArray(vector<int>& arr, int n) {
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        ans.push_back(arr[i]);
    }
    ans.push_back(arr[0]);
    return ans;
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

    vector<int> rotatedArray = rotateArray(arr, n);

    cout << "Array after one rotation: ";
    for (int i = 0; i < rotatedArray.size(); i++) {
        cout << rotatedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
