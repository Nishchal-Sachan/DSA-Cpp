#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int>& arr, int k) {
    vector<int> ans;
    int i = 1;  // Start from 1
    int idx = 0;  // This will iterate through the arr

    // Loop to find missing numbers
    while (ans.size() < k) {
        if (idx < arr.size() && arr[idx] == i) {
            // If i is in the array, move to the next element in the array
            idx++;
        } else {
            // If i is not in the array, it's a missing number
            ans.push_back(i);
        }
        i++;
    }

    return ans[k - 1];  // Return the k-th missing number
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};  // Example input array
    int k = 5;  // Example value for k

    // Call the kthMissing function and output the result
    cout << "The " << k << "th missing number is: " << kthMissing(arr, k) << endl;

    return 0;
}
