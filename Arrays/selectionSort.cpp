#include <iostream>
#include <vector>
using namespace std;

// Selection sort function
void selectionSort(vector<int>& arr, int n) {   
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

// Main function
int main() {
    vector<int> arr;
    int n;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // Display the array before sorting
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using selection sort
    selectionSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
