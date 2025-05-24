#include <bits/stdc++.h>
using namespace std;

class NStack {
    int* top;
    int* next;
    int* arr;
    int freeSpace;

public:
    // Initialize your data structure.
    NStack(int N, int S) {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        freeSpace = 0;

        // Initialize all stacks as empty
        for (int i = 0; i < N; i++) {
            top[i] = -1;
        }

        // Initialize the next array
        for (int i = 0; i < S - 1; i++) {
            next[i] = i + 1;
        }
        next[S - 1] = -1;
    }

    // Pushes 'x' into the Mth stack.
    bool push(int x, int m) {
        if (freeSpace == -1) {
            return false; // No space left
        }

        int idx = freeSpace;
        freeSpace = next[idx];

        arr[idx] = x;
        next[idx] = top[m - 1];
        top[m - 1] = idx;

        return true;
    }

    // Pops top element from Mth Stack.
    int pop(int m) {
        int idx = top[m - 1];
        if (idx == -1) {
            return -1; // Stack is empty
        }

        top[m - 1] = next[idx];
        next[idx] = freeSpace;
        freeSpace = idx;

        return arr[idx];
    }
};

// Driver code
int main() {
    int numStacks = 3;
    int arraySize = 10;
    NStack st(numStacks, arraySize);

    // Push elements into stack 1
    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 1);

    // Push elements into stack 2
    st.push(40, 2);
    st.push(50, 2);

    // Push elements into stack 3
    st.push(60, 3);

    // Pop from each stack
    cout << "Pop from stack 1: " << st.pop(1) << endl; // 30
    cout << "Pop from stack 2: " << st.pop(2) << endl; // 50
    cout << "Pop from stack 3: " << st.pop(3) << endl; // 60
    cout << "Pop from stack 3 again: " << st.pop(3) << endl; // -1 (empty)

    return 0;
}
