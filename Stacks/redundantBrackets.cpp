#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            if (ch == ')') {
                bool red = true;
                while (!st.empty() && st.top() != '(') {
                    char tp = st.top();
                    if (tp == '+' || tp == '-' || tp == '*' || tp == '/') {
                        red = false;
                    }
                    st.pop();
                }
                if (!st.empty()) st.pop();  // pop the '('
                if (red == true) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    bool result = findRedundantBrackets(expression);

    if (result) {
        cout << "The expression contains redundant brackets." << endl;
    } else {
        cout << "The expression does NOT contain redundant brackets." << endl;
    }

    return 0;
}
