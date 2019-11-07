#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int start, int firstend, int secondend)
{
    int *Merged, i, j, c=0;
    Merged = (int*) malloc (sizeof(int) * (secondend - start));
    
    // printf ("\n\n");

    // for (i=start; i<firstend; i++)
    // {
    //     printf ("%d\t", A[i]);
    // }

    // printf ("\n");

    // for (i=firstend; i<secondend; i++)
    // {
    //     printf ("%d\t", A[i]);
    // }

    // printf ("\n");


    for (i=start, j=firstend; j<secondend || i<firstend;)
    {
        if (i >= firstend)
        {
            Merged[c] = A[j];
            c++;
            j++;
        }
        else if (j >= secondend)
        {
            Merged[c] = A[i];
            c++;
            i++;
        }
        else if (A[i] < A[j])
        {
            Merged[c] = A[i];
            c++;
            i++;
        }
        else
        {
            Merged[c] = A[j];
            c++;
            j++;
        }
    }

    // for (i=start; i<secondend; i++)
    // {
    //     printf ("%d\t", Merged[i]);
    // }

    // printf ("\n\n");
    for (i=start; i<secondend; i++)
    {
        A[i] = Merged[i-start];
    }
    return;
}

void mergesort(int *A, int start, int end)
{
    if (end-start<2)
    {
        // printf("\nsingle\n");
        return;
    }

    // printf ("\n");

    // int i=0;
    // for (i=start; i<end; i++)
    // {
    //     printf ("%d\t", A[i]);
    // }

    // printf("\n");

    mergesort(A, start, (start+end)/2);
    mergesort(A, (start+end)/2, end);

    merge(A, start, (start+end)/2, end);

    return;
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

    mergesort (A, 0, n);

    show(A, n);

    return 0;
}