// shell sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Shell Sort function
void shellSort(int arr[], int n)
{
    // Start with a large gap and reduce it until gap is 1
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort on sub-arrays defined by gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Test the Shell Sort algorithm
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

    shellSort(arr, totalNumbers);

    printf("\nSorted array: \n");
    for (int i = 0; i < totalNumbers; i++)
        printf("%d ", arr[i]);

    return 0;
}
