// insertion sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insertionSort(int *arr, int size);

void printArray(int *arr, int size);

int main(void)
{
    int arr[MAX];

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Before sorting: ");
    printArray(arr, MAX);

    insertionSort(arr, MAX);

    printf("After sorting: ");
    printArray(arr, MAX);

    return 0;
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}