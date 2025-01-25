// Given an unsorted array arr[] of integers and an integer x, find the floor and
// ceiling of x in arr[].

// Floor of x is the largest element which is smaller than or equal to x. Floor 
// of x doesn’t exist if x is smaller than smallest element of arr[].
// Ceil of x is the smallest element which is greater than or equal to x. Ceil of 
// x doesn’t exist if x is greater than greatest element of arr[].

// Return an array of integers denoting the [floor, ceil]. Return -1 for floor or 
// ceiling if the floor or ceiling is not present.

// Examples:

// Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
// Output: 6, 8
// Explanation: Floor of 7 is 6 and ceil of 7 is 8.
// Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
// Output: 8, -1
// Explanation: Floor of 10 is 8 but ceil of 10 is not possible.



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        vector<int> ans;
        int floor = INT_MIN, ceil = INT_MAX;

        for (int i : arr) {
            if (i <= x && i > floor) {
                floor = i;
            }
            if (i >= x && i < ceil) {
                ceil = i;
            }
        }
        ans.push_back((floor == INT_MIN) ? -1 : floor); // If no floor found, return -1
        ans.push_back((ceil == INT_MAX) ? -1 : ceil);   // If no ceil found, return -1

        return ans;
    }
};

int main() {
    Solution solution;

    // Input
    int x;
    cout << "Enter the value of x: ";
    cin >> x;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function
    vector<int> result = solution.getFloorAndCeil(x, arr);

    // Output the results
    cout << "Floor: " << result[0] << endl;
    cout << "Ceil: " << result[1] << endl;

    return 0;
}
