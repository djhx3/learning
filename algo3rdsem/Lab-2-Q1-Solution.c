#include <stdio.h>

/*
 * @brief: Struct used to store the start and end index of the pivot partition
 * @param start: start index of the partition
 * @param end: end index of the partition
*/
typedef struct
{
    int start;
    int end;
} Partition;

/*
 * Forward definitions
*/

void swap(int *, int *);
Partition partition(int [], int, int);
void quickSort(int [], int, int);


int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * @param a: first number
 * @param b: second number
 * @brief: swap the values of a and b
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * @param arr[]: input array
 * @param l: left index
 * @param r: right index
 * @return: partition by pivot
*/
Partition partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int pivotEnd = l;
    while(pivotEnd <= r)
    {
        if(arr[pivotEnd] < pivot)
        {
            swap(&arr[l], &arr[pivotEnd]);
            l++;
            pivotEnd++;
        }
        else if(arr[pivotEnd] > pivot)
        {
            swap(&arr[pivotEnd], &arr[r]);
            r--;
        }
        else
        {
            pivotEnd++;
        }
    }

    Partition p;
    p.start = l;
    p.end = r;
    return p;
}

/*
 * @param arr[]: input array
 * @param l: left index
 * @param r: right index
 */
void quickSort(int arr[], int l, int r)
{
    Partition p = partition(arr, l, r);
    if(p.start-1 > l)
    {
        quickSort(arr, l, p.start-1);
    }
    if(p.end+1 < r)
    {
        quickSort(arr, p.end+1, r);
    }
}