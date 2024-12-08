// Find the first occurrence of the string pat in the string txt. The function returns an integer denoting the first occurrence of the string pat in txt (0-based indexing).

// Note: You are not allowed to use the inbuilt function. If there is no occurrence then return -1.

// Examples :

// Input: txt = "GeeksForGeeks", pat = "Fr"
// Output: -1
// Explanation: Fr is not present in the string GeeksForGeeks as substring.
// Input: txt = "GeeksForGeeks", pat = "For"
// Output: 5
// Explanation: For is present as substring in GeeksForGeeks from index 5 (0 based indexing

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
        int n = txt.length();
        int m = pat.length();

        // Check edge cases
        if (m > n) return -1; // Pattern is longer than text

        // Sliding window approach
        for (int i = 0; i <= n - m; i++) {
            string window = txt.substr(i, m); // Extract substring of size 'm'
            if (window == pat) {
                return i; // Return the starting index of the first occurrence
            }
        }
        return -1; // Pattern not found
    }
};

// Main function
int main() {
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt); // Input the text string
    cout << "Enter the pattern: ";
    getline(cin, pat); // Input the pattern string

    Solution solution;
    int index = solution.firstOccurence(txt, pat);

    if (index != -1) {
        cout << "The pattern is found at index: " << index << endl;
    } else {
        cout << "The pattern is not found in the text." << endl;
    }

    return 0;
}
