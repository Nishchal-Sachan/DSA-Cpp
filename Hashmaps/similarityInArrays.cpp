#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m) {
    unordered_map<int, int> freq;

    // Count elements of arr1
    for (int i = 0; i < n; i++) {
        freq[arr1[i]]++;
    }

    // Count elements of arr2
    for (int i = 0; i < m; i++) {
        freq[arr2[i]]++;
    }

    int common = 0;

    // Count elements present in both arrays
    for (auto i : freq) {
        if (i.second > 1) {
            common++;
        }
    }

    // return {common elements, union size}
    return make_pair(common, (int)freq.size());
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {3, 4, 5, 6};
    int n = arr1.size(), m = arr2.size();

    pair<int, int> ans = findSimilarity(arr1, arr2, n, m);
    cout << "Common Elements = " << ans.first << ", Union Size = " << ans.second << endl;
    return 0;
}
