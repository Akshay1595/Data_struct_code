/******************************************************************************

Print all the possible sums of an array elements 
Note: 0 is also an sum
for ex. if string is [1, 2, 3]
combinations are: []=0  [1]=1 [2]=2 [3]=3
[1, 2]=3 [1, 3]=4 [2, 3]=5 [1, 2, 3]=6

This approach can be used to compare sum with distinct sum
*******************************************************************************/

#include <stdio.h>
#define NUMBER_OF_ARRAY_ELEMENTS    (3)

void print_sums(int* array, int sum, int curr_index);

int main()
{
    int array[3] = {1,2,3};
    printf("Possible sums of array elements: ");
    print_sums(array, 0, 0);
    return 0;
}
void print_sums(int* array, int sum, int curr_index) {
    if (curr_index >= NUMBER_OF_ARRAY_ELEMENTS){
        printf(" %d ", sum);
        return;
    } else {
        print_sums(array, sum, curr_index+1);
        print_sums(array, sum+array[curr_index], curr_index+1);
    }
}
