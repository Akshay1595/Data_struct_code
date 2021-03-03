/******************************************************************************
The cost of stock on each day is given in an array A[] of size N. 
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
(0 3) (4 6)
Explanation:
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
(3 4)
Explanation:
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.

Reference: https://www.youtube.com/watch?v=JaosdXkUWTs

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tran {
    int buy;
    int sell;
}transaction;

void stockBuySell(int* arr, int n){
    int count = 0;
    transaction* transaction_array = (transaction*) malloc(sizeof(transaction) * ((n/2)+1));
    memset(transaction_array, 0, (sizeof(transaction) * ((n/2)+1)));
    int i = 0;
    if (n == 1)
        return;

    while ( i < (n-1)) {
        //buy stock first
        while( (i < (n-1)) && (arr[i] >= arr[i+1]))
            i++;
        if(i == (n-1))
            break;
        transaction_array[count].buy = i;
        
        // sell the stock purchased
        while ( (i < (n-1)) && (arr[i] <= arr[i+1]) )
            i++;
        transaction_array[count].sell = i;
        count++;
    }
    for (int i=0; i<count; i++) {
        printf("(%d,%d) ", transaction_array[i].buy, transaction_array[i].sell);
    }
    printf("\n");
}

void main() {
    int arr[7] = {100,180,260,310,40,535,695};
    printf(" transactions for array1 = \n");
    stockBuySell(arr, 7);
    
    int arr2[5] = {4,2,2,2,4};
    printf(" transactions for array2 = \n");
    stockBuySell(arr2, 5);
    
    int arr3[4] = {10, 10, 10, 10};
    printf(" transactions for array3 = \n");
    stockBuySell(arr3, 4);

    int arr4[2] = {1, 2};
    printf(" transactions for array4 = \n");
    stockBuySell(arr4, 2);
    
    int arr5[4] = {10, 9, 8, 7};
    printf(" transactions for array5 = \n");
    stockBuySell(arr5, 4);
    
}
