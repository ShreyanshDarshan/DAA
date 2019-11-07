#include<stdio.h>
#include<stdlib.h>

void swap_elem (int *A, int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int A[], int start, int end, int pivot)
{
    int pvt = A[pivot];
    swap_elem(A, end-1, pivot);
    int smallindex = -1;
    for (int i=start; i<end-1; i++)
    {
        if (A[i] < pvt)
        {
            smallindex++;
            swap_elem(A, start+smallindex, i);
        }
    }
    swap_elem(A, start+smallindex+1, end-1);
    return start+smallindex+1;
}

void quicksort (int A[], int start, int end)
{
    if (end>start+1)
    {
        int i;
        for (i = start; i < end; i++)
        {
            printf ("%d\t", A[i]);
        }
        int pivot = rand()%(end-start);
        printf ("\n%d\n", start+pivot);
        int part = partition(A, start, end, start+pivot);
        quicksort (A, start, part);
        quicksort (A, part+1, end);
    }
}

void show (int A[], int n)
{
    int i;
    printf ("\n");
    for (i = 0; i < n; i++)
    {
        printf ("%d\t", A[i]);
    }
    return;
}

int main()
{
    int *A, n, i;
    printf ("Enter size of array: ");
    scanf ("%d", &n);

    A = (int*) malloc(sizeof(int)*n);

    printf ("\nEnter elements of array: ");

    for (i=0; i<n; i++)
    {
       scanf ("%d", &A[i]);    
    }

    quicksort (A, 0, n);

    show(A, n);

    return 0;
}
//namrata jha 9810223164