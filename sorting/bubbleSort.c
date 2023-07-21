// bubble sort algorithm
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bubbleSort(int *arr, int size);
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

    bubbleSort(arr, MAX);

    printf("After sorting: ");
    printArray(arr, MAX);

    return 0;
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
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
