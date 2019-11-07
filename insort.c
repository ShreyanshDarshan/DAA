#include<stdio.h>
#include<stdlib.h>

void insort(int A[], int n)
{
    if (n>1)
    {
        int i,j=0;
        for (i=1; i<n; i++)
        {
            int cur = A[i];
            j=i-1;
            while (A[j]>cur && j>=0)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = cur;
        }
    }
    else
    {
        printf ("\nn<2\n");
        return;
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

    insort(A, n);
    show(A, n);

    return 0;
}