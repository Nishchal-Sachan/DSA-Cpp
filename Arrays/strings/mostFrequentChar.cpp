// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

// Examples:

// Input: s = "testsample"
// Output: 'e'
// Explanation: e is the character which is having the highest frequency.
// Input: s = "output"
// Output: 't'
// Explanation:  t and u are the characters with the same frequency, but t is lexicographically smaller.

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        int freq[26] = {0};  // Frequency array for characters 'a' to 'z'
        
        // Count the frequency of each character
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';  // Convert character to index
            freq[idx]++;
        }
        
        // Variables to store the character with the highest frequency
        int max = INT_MIN, ans = 0;
        int smax = INT_MIN, sans = 0;

        // Find the character with the maximum frequency
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max) {
                ans = i;
                max = freq[i];
            }
            if (freq[i] == max) {
                sans = i;
                smax = freq[i];
            }
        }

        // If two characters have the same frequency, choose the lexicographically smaller one
        char maxi = ans < sans ? 'a' + ans : 'a' + sans;
        return maxi;
    }
};

// Main function
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s; // Input string

    Solution solution;
    char maxChar = solution.getMaxOccuringChar(s);  // Get the max occurring character

    cout << "The maximum occurring character is: " << maxChar << endl;

    return 0;
}
