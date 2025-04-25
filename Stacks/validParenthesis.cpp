#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (!st.empty()) {
                char top = st.top();
                if ((s[i] == '}' && top == '{') ||
                    (s[i] == ']' && top == '[') ||
                    (s[i] == ')' && top == '(')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;  // closing bracket with no match
            }
        }
    }

    return st.empty();  // valid only if no unmatched brackets remain
}

int main() {
    vector<string> testCases = {
        "()", 
        "()[]{}", 
        "(]", 
        "([{}])", 
        "{[(])}", 
        "((({{{[[[]]]}}})))", 
        "", 
        "((((("
    };

    for (const string& s : testCases) {
        cout << "Input: " << s << " => ";
        if (isValidParenthesis(s)) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}
