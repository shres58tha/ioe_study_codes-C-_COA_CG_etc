//merge sorted
#include<stdio.h>
void merge(int arr[], int l, int m, int r);
// l= left index ; r= right index
void mergeSort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = l + (r - l) / 2;                      // get midpoint index
        // divide and conquer
        mergeSort(arr, l, m);                     // left half
        mergeSort(arr, m + 1, r);                 // right half
        merge(arr, l, m, r);                      // put all together in order
    }
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays this works only in newer version of the c as (const dyanamic array at runtime)
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    // note each array is sorted at this step as element with single element is trivally sorted so need to compare just the lowest elements
    //copy in order from lower and upper to original array comparing elemnts in order
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // when above loop is done there may be elemnts left in the lower and upper arrays
    // the remaing highest element in lower is lower than the lowest element in higher
    // simply copy all into the original one
    while (i < n1) {                              // Copy the remaining elements of L[], if there are any
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {                              // Copy the remaining elements of R[], if there are any
        arr[k] = R[j];
        j++;
        k++;
    }
}
//display
void display(int arr[], int size) {
    printf("\n\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}
// Driver code
int main() {
    int arr[50],arr_size,i;
    printf("Enter the number of elements in array :");
    scanf("%d",&arr_size);
    for(i=0;i<=arr_size-1;i++) {
        printf("arr[%d] :",i);
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,arr_size-1);
    display(arr,arr_size);
return 0;
}

// /*OUTPUT*/
//
// $ ./a.out
// Enter the number of elements in array :5
// arr[0] :9
// arr[1] :5
// arr[2] :8
// arr[3] :10
// arr[4] :6
//
//
// 5 6 8 9 10
//
