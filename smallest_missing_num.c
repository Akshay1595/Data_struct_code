/******************************************************************************
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Corner Case:
Input:
arrp[] = {7, 26, -9, -5, 1, 4, 7, 4, 5, 2, 3, 2}
Output = 6

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106

Referrence:
1] https://www.youtube.com/watch?v=-lfHWWMmXXM
2] https://www.youtube.com/watch?v=9SnkdYXNIzM
*******************************************************************************/

#include <stdio.h>


void swap (int* var1, int* var2) {
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


//Function to find the smallest positive number missing from the array.
int missingNumber(int arr[], int n) { 
    
    for (int i = 0; i<n ; i++) {
        while((arr[i] < n) && (arr[i] > 0) && (arr[(arr[i] - 1)] != arr[i]) ) {
            swap( &(arr[i]), &(arr[(arr[i] - 1)]) );
        }
    }
    
    for(int i=0; i<n ;i++) {
        if(arr[i] != i+1){
            return i+1;
        }
    }
    return n+1;
} 

void main() {
    int arr[2] = {0, 1};
    printf(" smallest missing Number point = %d \n",missingNumber(arr, 2));
}
