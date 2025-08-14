#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    vector<int> ans;

    // Generate all subarray sums
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];        // add next element
            ans.push_back(sum);   // store current subarray sum
        }
    }

    // Sort in ascending order
    sort(ans.begin(), ans.end());

    // Return k-th largest (last element is largest)
    return ans[ans.size() - k];
}

int main() {
    vector<int> arr = {3, -2, 5};
    int k = 2;
    cout << "K-th largest subarray sum: " << getKthLargest(arr, k) << endl;
    return 0;
}
