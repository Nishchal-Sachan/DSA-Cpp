#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> c;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        // Merge the two arrays until one is exhausted
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                c.push_back(a[i]);
                i++;
            } else {
                c.push_back(b[j]);
                j++;
            }
        }

        // Add remaining elements from `a` if any
        while (i < n) {
            c.push_back(a[i]);
            i++;
        }

        // Add remaining elements from `b` if any
        while (j < m) {
            c.push_back(b[j]);
            j++;
        }

        // Return the k-th element (1-based index)
        return c[k - 1];
    }
};

int main() {
    Solution solution;

    // Example inputs
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    // Find the k-th element
    int result = solution.kthElement(a, b, k);

    // Print the result
    cout << "The " << k << "-th element in the merged array is: " << result << endl;

    return 0;
}
