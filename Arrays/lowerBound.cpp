// Given a sorted array arr[] and a number target, the task is to find the
// lower bound of the target in this given array. The lower bound of a number 
// is defined as the smallest index in the sorted array where the element is
// greater than or equal to the given number.


// Note: If all the elements in the given array are smaller than the target,
// the lower bound will be the length of the array. 

// Examples :
// Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) 
// is greater than or equal to 9.




#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int s = 0, e = arr.size()-1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < target) {
            s = mid + 1;
        } else {
            e = mid-1;
        }
    }
    return s;

}

int main()
{
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    cout << lowerBound(arr, 9);
    return 0;
}
