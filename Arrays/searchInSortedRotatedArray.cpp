#include <iostream>
#include <vector>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct
// values).

// Prior to being passed to your function, nums is possibly rotated at an
//  unknown pivot index k (1 <= k < nums.length) such that the resulting
//   array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums
// [k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot
// index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target,
//  return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

class Solution
{
public:
    // Change the argument to accept a vector of integers
    int getPivot(vector<int> &arr, int n)
    {
        int s = 0, e = n - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;

            if (arr[mid] >= arr[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return s;
    }

    int binarySearch(vector<int> &arr, int start, int end, int key)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

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
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int size = nums.size();

        // Get the pivot (index of the smallest element)
        int pivot = getPivot(nums, size);

        // If target is within the right half (after the pivot)
        if (nums[pivot] <= target && target <= nums[size - 1])
        {
            return binarySearch(nums, pivot, size - 1, target);
        }
        else
        {
            // Otherwise, search the left half (before the pivot)
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {8, 13, 16, 2, 3, 4, 6}; // Example input array
    int ans = sol.search(nums, 16);
    cout << "fount at index :" << ans;
    return 0;
}
