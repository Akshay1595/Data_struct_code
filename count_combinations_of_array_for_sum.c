/******************************************************************************

Count all the possible combinations of array elements to get DESIRED_SUM
for ex. if string is [1, 2, 3]
combinations are: []=0  [1]=1 [2]=2 [3]=3
[1, 2]=3 [1, 3]=4 [2, 3]=5 [1, 2, 3]=6

if DESIRED_SUM is 3 
then Possible combinations are 2 
if DESIRED_SUM is 6/ 1/ 2/ 4/ 5
then Possible combinations are 1
*******************************************************************************/

#include <stdio.h>
#define NUMBER_OF_ARRAY_ELEMENTS    (3)
#define DESIRED_SUM                 (8)

int combination_for_sum(int* array, int sum, int curr_index);

int main()
{
    int array[3] = {1,2,3};
    printf("Possible combinations for sum = %d : %d", DESIRED_SUM, combination_for_sum(array, 0, 0));
    return 0;
}
int combination_for_sum(int* array, int sum, int curr_index) {
    if (curr_index >= NUMBER_OF_ARRAY_ELEMENTS){
        printf(" %d ", sum);
        if (sum == DESIRED_SUM)
            return 1;
        else
            return 0;
    } else {
        return ( combination_for_sum(array, sum, curr_index+1) +
        combination_for_sum(array, sum+array[curr_index], curr_index+1));
    }
}
