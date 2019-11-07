#include<stdio.h>
#include<stdlib.h>

void swap_elem (int *A, int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int A[], int start, int end, int pvt)
{
    int i=0;
    int pivot;
    for (i=start; i<end; i++)
    {
        if (A[i] == pvt)
        {
            pivot = i;
            break;
        }
    }
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

void bubsort(int *A, int start, int end)
{
    for (int i=start; i<end; i++)
    {   
        for (int j=start; j<end-1; j++)
        {
            if (A[j]>A[j+1])
            {
                swap_elem(A, j, j+1);
            }
        }
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

int kthSmallest (int *A, int start, int end, int k)
{
    if (start<=k && end>k && end>start)
    {
        int j=0, i=0, count=0;
        for (i=start; i<end; i+=5)
        {
            if (i+5<end)
            {
                bubsort(A, i, i+5);
                count++;
            }
            else
            {
                bubsort(A, i, end);
                count++;
            }
            
        }
        
        show(A+start, end-start);

        int *medians;
        medians = (int*) malloc(sizeof(int) * count);
        if ((end-start)%5)
        {
            count--;
        }
        for (i=2, j=0; j<count; j++, i+=5)
        {
            medians[j] = A[i];
        }
        if ((end-start)%5)
        {
            medians[count] = A[(count*5 + end)/2];
            printf ("extra median %d\n", medians[count]);
        }
        
        show(medians, count);
        int medofmed;
        if (count==1)
        {
            medofmed = medians[0];
        }
        else
        {
            medofmed = kthSmallest (medians, 0, count, count/2);
        }

        free(medians);
        
        printf ("\nmedofmed: %d\n", medofmed);

        int pos = partition(A, start, end, medofmed);

        if (pos == k)
        {
            return A[pos];
        }
        else if (pos > k)
        {
            return kthSmallest(A, start, pos, k);
        }
        else
        {
            return kthSmallest(A, pos+1, end, k);
        }
    }
    else
    {
        return A[start];
    }
    
}

int main()
{
    int *A, n, i, k;
    printf ("Enter size of array: ");
    scanf ("%d", &n);

    A = (int*) malloc(sizeof(int)*n);

    printf ("\nEnter elements of array: ");

    for (i=0; i<n; i++)
    {
       scanf ("%d", &A[i]);    
    }

    printf ("Enter value of k: ");
    scanf ("%d", &k);

    printf ("Kth smallest element: %d\n", kthSmallest(A, 0, n, k-1));

    return 0;
}
// 17 11 42 27 12 33 6 19 21 2 14 36 25 17 29 31 45 50
// 2	6	11	12	14	17	19	21	25	27	29	31	33	36	42	45	50