#include <iostream>
#include <vector>
using namespace std;


// Function to maintain the max heap property
void maxHeapify(vector<int>& arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap

        // Recursively heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildHeap(vector<int>& arr)
{
    int n = arr.size();
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

// Function to perform Heap Sort
void heapSort(vector<int>& arr)
{
    buildHeap(arr); // Create a max heap

    // Extract elements from heap one by one
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        maxHeapify(arr, i, 0); // Restore heap property
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr); // Perform heap sort

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " "; // Print sorted array
    }
    cout <<endl;

    return 0;
}
