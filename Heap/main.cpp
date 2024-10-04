#include <iostream>
using namespace std;

// Heap Order Property used == Max-Heap.
// Play on indexes.
class heap
{
public:
    int arr[100];
    int size;

    // Constructor
    heap()
    {
        arr[0] = -1; // 1-indexed array.
        size = 0;
    }

    // Insertion in Heap.
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Bottom -> Up approach.
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // Delete the root node of the CBT in Heap Virtually inside Heap Array.
    // Top -> Down approach.
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "No node to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;

        // Take root node to it's correct position.
        int i = 1;
        while (i <= size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (leftChild <= size && arr[leftChild] > arr[i])
            {
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }
            else if (rightChild <= size && arr[rightChild] > arr[i])
            {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify algorithm
// The array might not be already heap so we do recursion. We ensure Heapification of array.
// Top -> Down approach.
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left] > arr[i])
    {
        i = left;
    }
    if (right <= n && arr[right] > arr[i])
    {
        i = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, i);
    }
}

// Heap Sort
// We sort array heap always.
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step 1: swap
        swap(arr[size], arr[1]);

        size--;

        // step 2: Heapify
        heapify(arr, size, 1);
    }
}

int main()
{

    heap h;
    h.insert(20);
    h.insert(15);
    h.insert(31);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 34, 12, 32, 67, 8};
    int n = 5;
    // Heap Creation.
    // Bottom -> Up approach.
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing the sorted array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}