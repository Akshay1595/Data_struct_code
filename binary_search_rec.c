#include <stdio.h>
#define N 5

int binary_search(int* array, int num_to_search, int left, int right);

void main() {
    int array[N] = {};
    printf("Enter the array elements\n");
    for (int i = 0; i<N; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("Array elements entered are like:\n");
    for (int i = 0; i<N; i++)
        printf("%d ", array[i]);
    printf("\nEnter the number to be searched in an array:");
    int number;
    scanf("%d", &number);
    number = binary_search(array, number, 0, N-1);
    if (number == -1)
        printf("Element not found!\n");
    else
        printf("Element found at position = %d\n", number);
}

int binary_search(int* array, int num_to_search, int left, int right) {
    //printf("left = %d right = %d num_to_search = %d\n", left, right);
    if (left > right)
        return -1;
    else{
        int mid = (left + right) / 2;
        //printf("mid = %d\n",mid);
        if (array[mid] == num_to_search) {
            //printf("Element %d found at mid = %d\n", num_to_search, mid);
            return mid;
        }
        else if (num_to_search > array[mid])
            binary_search(array, num_to_search, mid+1, right);
        else if (num_to_search < array[mid])
            binary_search(array, num_to_search, left, mid-1);
    }
}
