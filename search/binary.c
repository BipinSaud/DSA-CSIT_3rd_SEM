// binary search
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *a, int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high)/2;
        if (key < a[mid])
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    int key = 5;
    int index = binary_search(a, 7, key);
    printf("index = %d\n", index);
    return 0;
}