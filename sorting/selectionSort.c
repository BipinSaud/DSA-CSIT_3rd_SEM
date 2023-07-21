// selection sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void selectionSort(int *arr, int size);

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

    selectionSort(arr, MAX);

    printf("After sorting: ");
    printArray(arr, MAX);

    return 0;
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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