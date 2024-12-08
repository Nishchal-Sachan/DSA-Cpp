#include <iostream>
using namespace std;

int findUnique(int *arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int unique = findUnique(arr, n);
    cout << "The unique element is: " << unique << endl;

    return 0;
}
