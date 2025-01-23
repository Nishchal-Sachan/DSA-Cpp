// Given a sorted array arr[] (with unique elements) and an integer k, find 
// the index (0-based) of the largest element in arr[] that is less than or equal to k. This element is called the "floor" of k. If such an element does not exist, return -1.

// Examples

// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 0
// Output: -1
// Explanation: No element less than 0 is found. So output is -1.
// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 5
// Output: 1
// Explanation: Largest Number less than 5 is 2 , whose index is 1.
// Input: arr[] = [1, 2, 8], k = 1
// Output: 0
// Explanation: Largest Number less than or equal to  1 is 1 , whose index is 0.




#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int k) {
    int ans;
        if(arr[0]>k){
            return -1;
        }
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]<k){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;

}

int main()
{
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    cout << lowerBound(arr, 9);
    return 0;
}
