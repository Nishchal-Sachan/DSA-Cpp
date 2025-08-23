#include <bits/stdc++.h>
using namespace std;

/*
   Function: longestCommonPrefix
   ---------------------------------
   Given an array of strings, this function finds the
   longest common prefix among them.

   arr -> vector of strings
   n   -> number of strings
*/
string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    // Traverse each character of the first string
    for (int i = 0; i < arr[0].size(); i++) {
        char ch = arr[0][i];   // take ith character from first string
        bool match = true;     // assume it matches in all strings

        // Compare this character with the ith character of all other strings
        for (int j = 1; j < n; j++) {
            // Condition 1: if current string is shorter than i
            // Condition 2: if ith character does not match
            if (i >= arr[j].size() || arr[j][i] != ch) {
                match = false;
                break;
            }
        }

        // If any mismatch found, break the loop
        if (!match) {
            break;
        } else {
            // If all matched, add character to the answer
            ans.push_back(ch);
        }
    }
    return ans;
}

/*
   Main Function
   -----------------------------
   - Takes input of number of strings
   - Reads each string into a vector
   - Calls longestCommonPrefix() to compute result
   - Prints the longest common prefix
*/
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string result = longestCommonPrefix(arr, n);

    if (result.empty()) {
        cout << "No common prefix found!" << endl;
    } else {
        cout << "Longest Common Prefix: " << result << endl;
    }

    return 0;
}
