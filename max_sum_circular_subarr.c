/******************************************************************************
Find max sum of circular Subarrays in array 
Circular Subarry is defined as:
arr[] = {1, 2, 3};
[1] [2] [3] [1, 2] [2, 3] [1 2 3] *[3 1]*

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.


Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23
Explanation: Sum of the circular 
subarray with maximum sum is 23
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int
getMax (int a, int b)
{
  return ((a > b) ? a : b);
}

int
get_max_subarray_sum (int *arr, int n)
{
  int max_subarray_sum = 0;
  int *max_sub_sum_array = (int *) malloc (n * sizeof (int));

  max_sub_sum_array[0] = arr[0];
  for (int i = 1; i < n; i++)
    {
      max_sub_sum_array[i] =
	getMax (arr[i], (max_sub_sum_array[i - 1] + arr[i]));
      //printf("max_sub_sum_array[%d] = %d\n", i, max_sub_sum_array[i]);
    }

  max_subarray_sum = max_sub_sum_array[0];
  for (int i = 1; i < n; i++)
    {
      max_subarray_sum = getMax (max_subarray_sum, max_sub_sum_array[i]);
      //printf("max_subarray_sum = %d\n", max_subarray_sum);
    }
  return max_subarray_sum;
}

int
get_circular_subarray_sum (int *arr, int n)
{
  int sum = 0;
  int normal_max_sum = get_max_subarray_sum (arr, n);
  //printf("Normal Max sum = %d\n",normal_max_sum);

  // handle the corner case
  if (normal_max_sum < 0)
    return normal_max_sum;

  // find sum of all elements
  int sum_of_all_elements = 0;
  for (int i = 0; i < n; i++)
    {
      sum_of_all_elements += arr[i];
    }
  //printf("Sum of all elements = %d\nNew array elements:\n", sum_of_all_elements);

  int min_subarray_sum = 0;
  // invert the array elements
  for (int i = 0; i < n; i++)
    {
      arr[i] *= (-1);
      //printf("%d ", arr[i]);
    }
  // Get minimum sum
  min_subarray_sum = get_max_subarray_sum (arr, n);
  //printf("\nmin_subarray_sum = %d\n", min_subarray_sum);

  // Get maximum cir Subarray sum
  int circular_max_sum = sum_of_all_elements + (min_subarray_sum);
  //printf("circular_max_sum = %d\n", circular_max_sum);
  // find max of normal_max_sum and circular_max_sum

  sum = getMax (normal_max_sum, circular_max_sum);
  //printf("Final return = %d\n", sum);
  return sum;
}

void
main ()
{
  int arr[7] = { 8, -8, 9, -9, 10, -11, 12 };
  printf ("Max circular Subarray sum of arr1 = %d\n",
	  get_circular_subarray_sum (arr, 7));

  int arr2[8] = { 10, -3, -4, 7, 6, 5, -4, -1 };
  printf ("Max circular Subarray sum of arr2 = %d\n",
	  get_circular_subarray_sum (arr2, 8));

  int arr3[4] = { 10, 10, 10, 10 };
  printf (" Max Subarray sum of arr3 = %d\n", get_max_subarray_sum (arr3, 4));

  int arr4[2] = { -1, 2 };
  printf (" Max Subarray sum of arr4 = %d\n", get_max_subarray_sum (arr4, 2));

  int arr5[4] = { -10, 9, -8, 7 };
  printf (" Max Subarray sum of arr4 = %d\n", get_max_subarray_sum (arr5, 4));

}
