#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    // Traverse both arrays
    while (i < n && j < m) {
        // If both elements are equal, add one and skip both
        if (a[i] == b[j]) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
        // Add the smaller element
        else if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    // Add remaining elements from `a`
    while (i < n) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from `b`
    while (j < m) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main() {
    // Input arrays
    vector<int> a = {1, 2, 2, 3};
    vector<int> b = {2, 3, 4, 5};

    // Call the function
    vector<int> result = findUnion(a, b);

    // Print the result
    cout << "Union of arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
