// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int p = 0, i = 1;
        while (i < nums.size() && p < nums.size())
        {
            if (nums[i] == 0)
            {
                i++;
            }
            else if (nums[p] == 0 && i < nums.size() && p < nums.size())
            {
                swap(nums[p], nums[i]);
                p++;
                i++;
            }
            if (nums[p] != 0)
            {
                p++;
                if (i <= p)
                {
                    i = p + 1;
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 0, 1};

    cout << "Input: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    solution.moveZeroes(nums);

    cout << "Output: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
