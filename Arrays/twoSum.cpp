#include <iostream>
#include <vector>
using namespace std;
// ProblemStatement:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15}; // Example input array
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);

    for (int num : ans)
    {
        cout << num << " "; // Output duplicates
    }
    return 0;
}