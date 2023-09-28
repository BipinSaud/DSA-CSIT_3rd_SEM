// binary search

#include <stdio.h>
#include <stdlib.h>

// binary search algorithm
int binary_search(int *arr, int size, int key)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;  // calculate the middle index of the array
        if (key < arr[mid])      // if the key is less than the middle element
            high = mid - 1;      // update the high index to search the left half of the array
        else if (key > arr[mid]) // if the key is greater than the middle element
            low = mid + 1;       // update the low index to search the right half of the array
        else                     // if the key is equal to the middle element
            return mid;          // return the index of the middle element
    }
    return -1; // return -1 if the key is not found in the array
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7};    // initialize an array of integers
    int key = 5;                            // initialize the key to be searched for
    int index = binary_search(arr, 7, key); // call the binary_search function to search for the key in the array
    printf("index = %d\n", index);          // print the index of the key in the array
    return 0;                               // return 0 to indicate successful execution
}