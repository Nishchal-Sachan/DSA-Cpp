Problem Statement:
Given an array of integers where each integer is in the range from 1 to n (inclusive), where n is the size of the array, you are supposed to find all the duplicate numbers in the array.

Key Insight:
Since the array elements are constrained to the range 1 to n, we can leverage this property to use the indices of the array to track visited numbers.
No extra space: We want to find duplicates without using extra space, which is why we manipulate the array in place.
The Plan:
Use the array indices to track occurrences:

For each number in the array, consider the value as an index (we subtract 1 from it to fit it in a zero-based index system).
If the number at that index is negative, it means we’ve already encountered that number before (since the negative sign was used to mark it).
If the number at that index is positive, negate it to mark that we've seen this number.
Step-by-Step Explanation:

Let's say nums[i] is a number in the array. The number’s absolute value gives us an index that we will mark by negating the value at that index.
If nums[abs(nums[i]) - 1] is already negative, then nums[i] is a duplicate because we have visited that index before.
Otherwise, we negate the value at that index to mark it as visited.








Detailed Explanation:
Traversal of the Array:

The for loop goes through every element in the array.
For each element nums[i], we first compute the index it should correspond to using abs(nums[i]) - 1. This converts the number to a zero-based index, so for a number 3, it will correspond to index = 2 (since we subtract 1).
Marking the Index:

If nums[index] is negative, it means that this index has been visited before (because we negated the value there during a previous pass).
When this happens, we know that nums[i] is a duplicate, so we add it to the ans vector.
If nums[index] is positive, it means we haven’t visited this index yet. We then negate the value at nums[index] to mark it as visited.
Example Walkthrough:

Let’s say the input is:

cpp
Copy code
nums = {4, 3, 2, 7, 8, 2, 3, 1}
First iteration (i = 0, nums[i] = 4):

index = abs(4) - 1 = 3
nums[3] = 7 (positive), so we negate nums[3] to -7.
Second iteration (i = 1, nums[i] = 3):

index = abs(3) - 1 = 2
nums[2] = 2 (positive), so we negate nums[2] to -2.
Third iteration (i = 2, nums[i] = -2):

index = abs(-2) - 1 = 1
nums[1] = 3 (positive), so we negate nums[1] to -3.
Fourth iteration (i = 3, nums[i] = -7):

index = abs(-7) - 1 = 6
nums[6] = 3 (positive), so we negate nums[6] to -3.
Fifth iteration (i = 4, nums[i] = 8):

index = abs(8) - 1 = 7
nums[7] = 1 (positive), so we negate nums[7] to -1.
Sixth iteration (i = 5, nums[i] = -2):

index = abs(-2) - 1 = 1
nums[1] = -3 (negative), so this is a duplicate. We add 2 to the result list: ans = [2].
Seventh iteration (i = 6, nums[i] = -3):

index = abs(-3) - 1 = 2
nums[2] = -2 (negative), so this is a duplicate. We add 3 to the result list: ans = [2, 3].
Eighth iteration (i = 7, nums[i] = -1):

index = abs(-1) - 1 = 0
nums[0] = 4 (positive), so we negate nums[0] to -4.
Final Output:

After all iterations, we’ve found the duplicates 2 and 3, and the final output is:
cpp
Copy code
[2, 3]
Time Complexity:
Time complexity is O(n) because we are traversing the array once, and each element is processed in constant time.
Space complexity is O(1) for the in-place manipulation of the array (not counting the space used to store the result list ans).
Why This Works:
We only need to traverse the array once and use the indices of the array itself to mark the elements we’ve already seen, which is why this solution is efficient in both time and space.


