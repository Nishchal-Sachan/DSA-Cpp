#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    stack<int> s;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    int n = arr.size();

    vector<int> result = nextGreaterElement(arr, n);

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << result[i] << endl;
    }

    return 0;
}
