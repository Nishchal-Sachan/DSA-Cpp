#include <iostream>
using namespace std;

// two pointer approach
void reverseArray(int arr[], int size)
{
    int start = 0, end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void printArray(int arr[], int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    reverseArray(arr, 7);

    printArray(arr,7);

    return 0;
}