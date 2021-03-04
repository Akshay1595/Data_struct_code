/******************************************************************************
Kadane's Algorithm to find max sum of Subarrays in array 
Subarry is defined as:
arr[] = {1, 2, 3};
[1] [2] [3] [1, 2] [2, 3] [1 2 3]

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
Example 2:

Input:
N = 4
arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1 
of element (-1)
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int getMax(int a, int b) {
    return ((a>b)? a: b);
}

int get_max_subarray_sum(int* arr, int n) {
    int max_subarray_sum = 0;
    int* max_sub_sum_array = (int *)malloc(n * sizeof (int));
    
    max_sub_sum_array[0]  = arr[0];
    for (int i = 1; i<n ; i++) {
        max_sub_sum_array[i] = getMax(arr[i], (max_sub_sum_array[i-1] + arr[i]));
        //printf("max_sub_sum_array[%d] = %d\n", i, max_sub_sum_array[i]);
    }
    
    max_subarray_sum = max_sub_sum_array[0];
    for (int i = 1; i <n; i++) {
        max_subarray_sum = getMax(max_subarray_sum, max_sub_sum_array[i]);
        //printf("max_subarray_sum = %d\n", max_subarray_sum);
    }
    return max_subarray_sum;
}

void main() {
    int arr[5] = {1,2,3,-2,5};
    printf(" Max Subarray sum of arr1 = %d\n", get_max_subarray_sum(arr, 5));
    
    int arr2[4] = {-1,-2,-3,-4};
    printf(" Max Subarray sum of arr2 = %d\n", get_max_subarray_sum(arr2, 4));
    
    int arr3[4] = {10, 10, 10, 10};
    printf(" Max Subarray sum of arr3 = %d\n", get_max_subarray_sum(arr3, 4));

    int arr4[2] = {-1, 2};
    printf(" Max Subarray sum of arr4 = %d\n", get_max_subarray_sum(arr4, 2));
    
    int arr5[4] = {-10, 9, -8, 7};
    printf(" Max Subarray sum of arr4 = %d\n", get_max_subarray_sum(arr5, 4));
}
