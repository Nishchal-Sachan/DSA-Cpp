// -----------------------------------------------------------
//  Dutch National Flag Algorithm - Sort Colors (0,1,2)
//  Author: ChatGPT for Nishchal
// -----------------------------------------------------------
//  Problem:
//  Given an array consisting of 0s, 1s, and 2s,
//  sort the array in-place so that all 0s come first,
//  then 1s, then 2s.
//
//  We use THREE POINTERS:
//    low  -> position for next 0
//    mid  -> current element pointer
//    high -> position for next 2
//
//  Time Complexity: O(n)
//  Space Complexity: O(1)
// -----------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
//  Function: sortColors
//  Implements the Dutch National Flag algorithm
// -----------------------------------------------------------
void sortColors(vector<int>& nums) {

    int low = 0;                 // Region for 0s starts at index 0
    int mid = 0;                 // Current index we are processing
    int high = nums.size() - 1;  // Region for 2s starts from end

    // Process elements until mid crosses high
    while (mid <= high) {

        // ---------------------------------------------------
        // CASE 1 → nums[mid] == 0
        //   - 0 belongs to the front
        //   - swap it with nums[low]
        //   - increase both low and mid
        // ---------------------------------------------------
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        // ---------------------------------------------------
        // CASE 2 → nums[mid] == 1
        //   - 1 belongs in the middle
        //   - just move mid forward
        //   - no swap needed
        // ---------------------------------------------------
        else if (nums[mid] == 1) {
            mid++;
        }

        // ---------------------------------------------------
        // CASE 3 → nums[mid] == 2
        //   - 2 belongs to the back
        //   - swap nums[mid] with nums[high]
        //   - decrease high
        //   - DO NOT increment mid because the swapped element
        //     from nums[high] has NOT been processed yet
        // ---------------------------------------------------
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// -----------------------------------------------------------
//  Main function (for testing the algorithm)
// -----------------------------------------------------------
int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    sortColors(nums);

    cout << "After sorting : ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
