#include <iostream>
using namespace std;

int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {2, 4, 3, 2, 3, 4, 5};
    cout << findUnique(arr, 7);
    return 0;
}