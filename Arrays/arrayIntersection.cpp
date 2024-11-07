#include <iostream>
using namespace std;

void ArrayIntersection(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " "; // Print the intersection element
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int arr1[] = {1, 4, 5, 8, 9};
    int arr2[] = {2, 4, 5, 9};

    // Assuming arr1 has 7 elements and arr2 has 5 elements
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    ArrayIntersection(arr1, arr2, n, m);
    return 0;
}
