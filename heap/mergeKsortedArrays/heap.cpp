#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int rows;
    int cols;
    Node(int data, int rows, int cols) {
        this->data = data;
        this->rows = rows;
        this->cols = cols;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step 1: Push the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        if (!kArrays[i].empty()) {
            Node* temp = new Node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    }

    vector<int> ans;

    // Step 2: Process the heap until it’s empty
    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int i = temp->rows;
        int j = temp->cols;

        // Push next element from the same array if it exists
        if (j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}


// Main function for testing
int main() {
    vector<vector<int>> kArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = kArrays.size();

    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);

    cout << "Merged Sorted Array: ";
    for (int val : mergedArray) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
