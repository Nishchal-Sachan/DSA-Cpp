#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    // Constructor initializes heap with size 0 and arr[0] unused
    heap()
    {
        arr[0] = -1; // 1-based indexing for easier calculations
        size = 0;
    }

    // Insert a value into the max-heap
    void insert(int val)
    {
        size += 1;
        int idx = size;
        arr[idx] = val;

        // Bubble up to maintain max-heap property
        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Delete the root (maximum) element from the heap
    void deleteHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty, cannot delete.\n";
            return;
        }

        // Replace root with last element and reduce heap size
        arr[1] = arr[size];
        size--;

        int idx = 1;

        // Bubble down to maintain max-heap property
        while (idx <= size)
        {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            int largest = idx;

            // Check if left child exists and is greater
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }

            // Check if right child exists and is greater
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }

            // If largest is not the current index, swap and continue
            if (largest != idx)
            {
                swap(arr[idx], arr[largest]);
                idx = largest;
            }
            else
            {
                break; // Heap property restored
            }
        }
    }

    // Heapify function used in heap sort to maintain max-heap property at subtree rooted at i
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        // Check left child
        if (left <= n && arr[left] > arr[largest])
        {
            largest = left;
        }

        // Check right child
        if (right <= n && arr[right] > arr[largest])
        {
            largest = right;
        }

        // If largest is not root, swap and heapify recursively
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Print current heap elements
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build max heap - heapify from last non-leaf node down to root
    for (int i = n / 2; i >= 1; i--)
    {
        // Use a temporary heap object to call heapify
        heap h;
        h.heapify(arr, n, i);
    }

    int size = n;
    // Extract elements from heap one by one
    while (size > 1)
    {
        swap(arr[1], arr[size]); // Move max to end
        size--;                  // Reduce heap size
        heap h;
        h.heapify(arr, size, 1); // Heapify root after extraction
    }
}

int main()
{
    heap h;

    // Insert elements into heap
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(40);
    h.insert(30);

    cout << "Heap array after insertions: ";
    h.printHeap();

    // Delete max element (root)
    h.deleteHeap();

    cout << "Heap array after deleting max element: ";
    h.printHeap();

    // Prepare array for heap sort (1-based indexing)
    int arr[6] = {-1, 10, 20, 5, 40, 30}; // index 0 unused
    int n = 5;

    cout << "Array before heap sort: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    heapSort(arr, n);

    cout << "Array after heap sort: ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
