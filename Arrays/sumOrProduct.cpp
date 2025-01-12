// Problem statement
// You are given a number ‘N’ and a query ‘Q.’ If ‘Q’ is 1, then you have to 
// return the sum of all integers from 1 to ‘N,’ else if ‘Q’ is equal to 2
// then
// you have to return the product of all integers from 1 to ‘N.’ Since the
// product can be very large, return it modulo 10 ^ 9 + 7.

// For example

// Given ‘N’ = 4, ‘Q’ = 1. 
// Then the answer is 10 because the sum of all integers between 1 and 4 are
// 1,

// 2, 3, and 4. Hence 1 + 2 + 3 + 4 is equal to 10.


#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

long long int sumOrProduct(long long int n, long long int q)
{
	if(q==1){
		long long int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
		}
		return sum;
	}
	if(q==2){
		long long int product=1;
		for(int i=1;i<=n;i++){
			product=product*i%1000000007;
		}
		return product;
	}
}


int main() {
    long long int n, q;

    // Input values for n and q
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of q (1 for sum, 2 for product): ";
    cin >> q;

    // Validate q
    if (q != 1 && q != 2) {
        cout << "Invalid value of q. Please enter 1 for sum or 2 for product." << endl;
        return 1;
    }

    // Call the function and display the result
    long long int result = sumOrProduct(n, q);
    cout << "The result is: " << result << endl;

    return 0;
}