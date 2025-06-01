#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& arr, int n) {
    stack<int> s;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
        // Pop until we find a strictly smaller element
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack empty, no smaller to the right
        ans[i] = s.empty() ? -1 : s.top();

        // Push current for future elements to the left
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr, n);

    for (int x : result) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
