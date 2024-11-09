#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0, end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[7] = {2, 3, 4, 6, 8, 13, 16};
    int size = 7;
    int key = 3;
    int found = binarySearch(arr, size, key);

    if (found != -1)
    {
        cout << "Key found at index: " << found;
    }
    else
    {
        cout << "Key not found!";
    }
}