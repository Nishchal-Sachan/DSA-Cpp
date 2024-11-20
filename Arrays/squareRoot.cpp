// Problem statement
// You are given a positive integer ‘n’.



// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).



// Example:
// Input: ‘n’ = 7

// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6
// Sample Output 1:
// 2
// Explanation of Sample Input 1:
// The square root of the given number 6 lies between 2 and 3, so the floor value is 2.
// Sample Input 2:
// 100
// Sample Output 2:
// 10
// Explanation of Sample Output 2:
// The square root of the given number 100 is 10.
// Expected Time Complexity:
// Try solving this in O(log(n)).
#include <iostream>
using namespace std;

long long int floorSqrt(int n)
{
    int s=0,e=n;
    long long int ans=-1;
    long long int mid = s+(e-s)/2;
    while (s<=e){
        long long int sq=mid*mid;
        if (sq==n){
            return mid;
        } if( sq<n ){
            ans = mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a number to find its floor square root: ";
    cin >> n;

    if (n < 0) {
        cout << "Square root of negative numbers is not defined in real numbers." << endl;
    } else {
        long long int result = floorSqrt(n);
        cout << "The floor square root of " << n << " is: " << result << endl;
    }

    return 0;
}
