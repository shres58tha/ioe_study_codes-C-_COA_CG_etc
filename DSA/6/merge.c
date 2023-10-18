#include<stdio.h>

int min (int x, int y) {
    if (x<y)
        return x;
    return y;
}
void CopyArray(int B[], int A[],int n){
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}
void BottomUpMerge(int A[],int iLeft, int iRight,int iEnd,int B[]);
// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(int A[],int B[],int n)
{
    // Each 1-element run in A is already "sorted".
    // Make successively longer sorted runs of length 2, 4, 8, 16... until the whole array is sorted.
    for (int width = 1; width < n; width = 2 * width)
    {
        // Array A is full of runs of length width.
        for (int i = 0; i < n; i = i + 2 * width)
        {
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if (i+width >= n) )
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        // Now work array B is full of runs of length 2*width.
        // Copy array B to array A for the next iteration.
        // A more efficient implementation would swap the roles of A and B.
        CopyArray(B, A, n);
        // Now array A is full of runs of length 2*width.
    }
}

//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
void BottomUpMerge(int A[],int iLeft, int iRight,int iEnd,int B[])
{
    int i = iLeft, j = iRight, k;
    // While there are elements in the left or right runs...
    for (k = iLeft; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

void display(int arr[], int size) {
    int i;
    printf("\n\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

// Driver code
int main() {
    int arr[50],arr_size,i;
    printf("Enter the number of elements in array :");
    scanf("%d",&arr_size);
    display(arr,arr_size);
    for(i=0;i<=arr_size-1;i++) {
        printf("arr[%d] :",i);
        scanf("%d",&arr[i]);
    }
    display(arr,arr_size);
    BottomUpMergeSort(arr,0,arr_size-1);
    display(arr,arr_size);

    return 0;
}
