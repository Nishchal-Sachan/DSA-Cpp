#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            count[ch]++;
            q.push(ch);

            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    q.pop();
                } else {
                    ans.push_back(q.front());
                    break;
                }
            }

            if (q.empty()) {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main() {
    string s;
    cout << "Enter the stream string: ";
    cin >> s;

    Solution sol;
    string result = sol.FirstNonRepeating(s);

    cout << "First non-repeating characters: " << result << endl;
    return 0;
}
