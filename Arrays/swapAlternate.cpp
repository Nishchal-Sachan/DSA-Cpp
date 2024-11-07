#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{
    int start = 0, end = size - 1;

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    swapAlternate(arr, 7);

    printArray(arr, 7);

    return 0;
}