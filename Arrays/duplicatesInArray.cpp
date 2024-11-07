#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans; // This will hold our result, the list of duplicates.

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Take the absolute value of nums[i] and map it to an index in the range [0, n-1]
            int index = abs(nums[i]) - 1; // We subtract 1 because the numbers range from 1 to n, but arrays are 0-indexed.

            // Check if the value at this index is already negative
            if (nums[index] < 0)
            {
                // If it's negative, that means we've already visited this index, so the number is a duplicate.
                ans.push_back(abs(nums[i])); // Add the number to the result (using abs because it might have been negated)
            }
            else
            {
                // Otherwise, negate the value at this index to mark it as visited
                nums[index] = -nums[index];
            }
        }

        return ans; // Return the list of duplicates.
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; // Example input array
    vector<int> duplicates = sol.findDuplicates(nums);

    for (int num : duplicates)
    {
        cout << num << " "; // Output duplicates
    }
    return 0;
}
