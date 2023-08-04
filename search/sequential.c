// sequential search
#include <stdio.h>
#include <stdlib.h>

int sequential_search(int *a, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    int key = 5;
    int index = sequential_search(a, 7, key);
    printf("index = %d\n", index);
    return 0;
}

