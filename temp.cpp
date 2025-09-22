#include <bits/stdc++.h>
using namespace std;

void findMinimumSum() {
    int numElements;
    long long moduloBase;
    cin >> numElements >> moduloBase;

    vector<int> numbers(numElements);
    vector<int> frequency(moduloBase, 0);
    
    long long currentSum = 0;
    for (int i = 0; i < numElements; ++i) {
        cin >> numbers[i];
        frequency[numbers[i]]++;
        currentSum += numbers[i];
    }

    long long minSum = currentSum;

    for (long long shift = 1; shift < moduloBase; ++shift) {
        currentSum += numElements;

        long long valueBecomesZero = (moduloBase - shift) % moduloBase;
        
        currentSum -= (long long)frequency[valueBecomesZero] * moduloBase;
        
        minSum = min(minSum, currentSum);
    }
    
    cout << minSum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        findMinimumSum();
    }
}
