#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if the array is sorted and rotated
int removeDuplicates(vector<int> &nums)
{
    
    int idx = 0; // Points to the last unique element's position.
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[idx]) { // Found a new unique element.
            idx++;
            nums[idx] = nums[i]; // Move the unique element to the next position.
        }
    }
    return idx;
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // Test case
    cout << removeDuplicates(arr);
}
