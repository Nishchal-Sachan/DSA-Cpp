#include<iostream>
#include<deque>
using namespace std;

int sum(int* arr, int n, int k) {
    int ans = 0;
    deque<int> maxi;
    deque<int> mini;

    for (int i = 0; i < k; i++) {
        while (!maxi.empty() && arr[i] >= arr[maxi.back()]) {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[i] <= arr[mini.back()]) {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    ans += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++) {
        while (!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k) {
            mini.pop_front();
        }

        while (!maxi.empty() && arr[i] >= arr[maxi.back()]) {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[i] <= arr[mini.back()]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sum(arr, 7, k) << endl;  // Output should be 18
    return 0;
}
