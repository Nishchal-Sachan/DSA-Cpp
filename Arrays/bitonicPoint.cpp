// Given an array of integers arr[] that is first strictly increasing and then
// maybe strictly decreasing, find the bitonic point, that is the maximum
// element in the array.
// Bitonic Point is a point before which elements are strictly increasing and
// after which elements are strictly decreasing.

// Examples:

// Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
// Output: 8
// Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and
// elements after 8 are strictly decreasing [3].

// Input: arr[] = [10, 20, 30, 40, 50]
// Output: 50
// Explanation: Elements before 50 are strictly increasing [10, 20, 30 40] and
// there are no elements after 50.

// Input: arr[] = [120, 100, 80, 20, 0]
// Output: 120
// Explanation: There are no elements before 120 and elements after 120 are
// strictly decreasing [100, 80, 20, 0].

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> &arr, int s, int e)
{
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return e;
}
int findMaximum(vector<int> &arr)
{
    int n = arr.size() - 1;
    if (arr[0] < arr[1])
    {
        return arr[getPivot(arr, 0, n)];
    }
    else
    {
        return arr[getPivot(arr, n, 0)];
    }
}

int main()
{
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {1, 2, 4, 5, 7, 8, 3};
    vector<int> arr3={120, 100, 80, 20, 0};
    cout << findMaximum(arr3);
    return 0;
}
