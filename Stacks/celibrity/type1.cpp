#include <bits/stdc++.h>
using namespace std;

// Simulated party matrix where M[i][j] == 1 if person i knows person j
vector<vector<int>> M;

// Helper function as described
bool knows(int A, int B) {
    return M[A][B] == 1;
}

// Celebrity finder function
int findCelebrity(int n) {
    stack<int> s;

    // Step 1: Push everyone onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();

        if (knows(a, b)) {
            s.push(b); // a can't be celebrity
        } else {
            s.push(a); // b can't be celebrity
        }
    }

    // Step 3: Verify candidate
    if (s.empty()) return -1;

    int candidate = s.top();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
    }

    return candidate;
}

// Main function for testing
int main() {
    int n = 4; // Number of people at the party

    // Initialize the matrix (example where person 2 is the celebrity)
    M = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}, // Person 2 knows no one
        {0, 1, 1, 0}
    };

    int celeb = findCelebrity(n);

    if (celeb == -1) {
        cout << "No celebrity found in the party." << endl;
    } else {
        cout << "Celebrity ID is: " << celeb << endl;
    }

    return 0;
}
