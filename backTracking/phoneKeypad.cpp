#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Recursive backtracking function to generate combinations
void backtrack(string &s, int index, string &current, vector<string> &result, unordered_map<char, string> &phonePad) {
    // Base case: if we processed all digits, store the current combination
    if (index == s.length()) {
        result.push_back(current);
        return;
    }

    char digit = s[index];         // Current digit to process
    string letters = phonePad[digit];  // Possible letters for the digit

    // Try each letter mapped to the current digit
    for (char letter : letters) {
        current.push_back(letter);        // Choose a letter
        backtrack(s, index + 1, current, result, phonePad);  // Explore next digit
        current.pop_back();               // Backtrack (remove last letter)
    }
}

// Main function to generate all letter combinations from the digit string
vector<string> combinations(string s) {
    vector<string> result;

    // If input is empty, return empty result
    if (s.empty()) return result;

    // Map digits to corresponding letters (classic phone keypad)
    unordered_map<char, string> phonePad = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    string current = "";  // Holds the current combination being built

    // Start recursive backtracking from index 0
    backtrack(s, 0, current, result, phonePad);

    return result;
}

// Example driver function to demonstrate usage
int main() {
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = combinations(digits);

    cout << "Possible combinations:\n";
    for (string &combo : result) {
        cout << combo << " ";
    }
    cout << endl;

    return 0;
}
