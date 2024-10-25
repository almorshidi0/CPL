#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int arr[] = {2, 4, 6, 7, 9, 29, 45, 46, 49, 50, 51};

    printf("%d\n", binsearch(9, arr, 10));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high && x != v[mid]){
        mid = (low+high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(x != v[mid]) /* no match */
        mid = -1;

    return mid;
}