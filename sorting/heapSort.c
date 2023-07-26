// heap sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the subtree rooted at index i, assuming its left and right subtrees are already max heaps
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]); // Move current root to the end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

// Test the Heap Sort algorithm
int main()
{
    int totalNumbers;
    printf("Enter the total number of elements: ");
    scanf("%d", &totalNumbers);
    int arr[totalNumbers];

    for (int i = 0; i < totalNumbers; i++)
        arr[i] = rand() % 100;

    printf("Original array: \n");
    for (int i = 0; i < totalNumbers; i++)
        printf("%d ", arr[i]);

    heapSort(arr, totalNumbers);

    printf("\nSorted array: \n");
    for (int i = 0; i < totalNumbers; i++)
        printf("%d ", arr[i]);

    return 0;
}
