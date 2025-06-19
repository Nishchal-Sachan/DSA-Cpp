#include <iostream>
#include <vector>
using namespace std;

// Bubble sort function
void bubbleSort(vector<int>& arr, int n) {   
    // base case
    if(n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
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

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Display the array after sorting
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
