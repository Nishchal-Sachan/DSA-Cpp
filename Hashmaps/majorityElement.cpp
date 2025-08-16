#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
    unordered_map<int, int> m;

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    // Check if any element occurs more than n/2 times
    for (auto i : m) {
        if (i.second > n / 2) {
            return i.first;  // majority element found
        }
    }

    return -1; // no majority element
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findMajorityElement(arr, n);
    return 0;
}
