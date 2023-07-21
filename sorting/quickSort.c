// quicksort
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void quickSort(int *arr, int low, int high);

int partition(int *arr, int low, int high);

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

    quickSort(arr, 0, MAX - 1);

    printf("After sorting: ");
    printArray(arr, MAX);

    return 0;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}