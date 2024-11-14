#include <iostream>
using namespace std;

int pivotInArray(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    int arr[7] = {8, 13, 16, 2, 3, 4, 6};
    int size = 7;
    int pivot = pivotInArray(arr, size);
    cout << "pivot index :" << pivot;
    return 0;
}