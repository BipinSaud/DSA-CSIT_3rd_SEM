// merge sort
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main()
{
    int arr[MAX], i, n;
    printf("Enter total number of elements:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("After merge sorting elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int tmp[MAX];
    int i, j, k;
    j = m + 1;
    for (i = l; i <= m && j <= r;)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= m)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++)
    {
        arr[i] = tmp[j];
    }
}

void mergeSort(int arr[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
