#include<stdio.h>
#include<stdlib.h>

int binsearch( int *A, int start, int end, int q)
{
    int comp = A[(start+end)/2];
    if (comp ==  q)
    {
        return (start+end)/2;
    }
    
    if (end > start)
    {
        if (q<comp)
        {
            return binsearch(A, start, (start+end)/2, q);
        }
        else
        {
            return binsearch(A, (start+end)/2+1, end, q);
        }
    }
    
    return -1;
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
    int *A, n, i, q;
    printf ("Enter size of array: ");
    scanf ("%d", &n);

    A = (int*) malloc(sizeof(int)*n);

    printf ("\nEnter elements of array: ");

    for (i=0; i<n; i++)
    {
       scanf ("%d", &A[i]);    
    }

    printf ("Enter search element: ");
    scanf ("%d", &q);

    printf ("Search element at: %d", binsearch(A, 0, n, q));

    return 0;
}
//1 3 5 7 8 9 10