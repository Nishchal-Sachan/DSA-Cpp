#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int stdCount = 1; // Start with the first student
    int pgSum = 0;

    for (int i = 0; i < n; i++) {
        if (pgSum + arr[i] <= mid) {
            pgSum += arr[i];
        } else {
            stdCount++;
            if (stdCount > m || arr[i] > mid) {
                return false;
            }
            pgSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1; // Impossible to allocate if students > books
    }

    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int n = books.size();
    int m = 2; // Number of students
    cout << "Minimum of the maximum pages: " << findPages(books, n, m) << endl;
    return 0;
}