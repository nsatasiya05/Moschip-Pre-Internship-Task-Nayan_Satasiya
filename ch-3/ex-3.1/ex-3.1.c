#include <stdio.h>

// Original binary search (two tests inside loop)
int binsearch_old(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// Improved version: only one test inside the loop
int binsearch_new(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (v[low] == x) ? low : -1;
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int pos1 = binsearch_old(x, arr, n);
    int pos2 = binsearch_new(x, arr, n);

    printf("Old binary search index: %d\n", pos1);
    printf("New binary search index: %d\n", pos2);

    return 0;
}
