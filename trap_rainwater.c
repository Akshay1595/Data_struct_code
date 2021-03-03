/******************************************************************************
 * Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 
 __
| |   __
| |..| |
| |..| |
| |..| |
Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
*******************************************************************************/

#include <stdio.h>

static inline int get_min(int i, int j) {
    return ((i < j)? i : j);
}

// arr[]: input array
// n: size of array
// Function to find the maximum index difference.
int maxIndexDiff(int arr[], int n) { 
    // Your code here
    int* lmax = (int *) malloc (sizeof(int) * n);
    int* rmax = (int *) malloc (sizeof(int) * n);
    
    printf("Lmax array is like: ");
    lmax[0] = arr[0]; rmax[n-1] = arr[n-1];
    for(int i=1; i<n ; i++) {
        if (arr[i] > lmax[i-1]) {
            lmax[i] = arr[i];
        }else
            lmax[i] = lmax[i-1];
        printf("%d ",lmax[i]);
    }

    printf("\nRmax array is like: ");
    for(int i=n-2; i>=0 ; i--) {
        if (arr[i] > rmax[i+1]) {
            rmax[i] = arr[i];
        }else
            rmax[i] = rmax[i+1];
        printf("%d ",rmax[i]);
    }
    printf("\n");
    int result = 0;
    int min = 0;
    int curr = 0;
    for (int i=1; i<(n-1); i++){
        min = get_min(lmax[i], rmax[i]);
        curr = min - arr[i];
        if (curr > 0)
            result += curr;
        printf("arr[%d] = %d min = %d curr = %d result = %d\n", i, arr[i], min, curr, result);
    }
    return result;
}

void main() {
    int arr[6] = {3,0,0,2,0,4};
    printf(" 1] Water Units = %d \n", maxIndexDiff(arr, 6));
    int arr2[4] = {7,4,0,9};
    printf(" 2] Water Units = %d \n", maxIndexDiff(arr2, 4));
    int arr3[3] = {6,9,9};
    printf(" 3] Water Units = %d \n", maxIndexDiff(arr3, 3));
}
