#include <stdio.h>
#include <stdlib.h>

void merge_k_sorted_array(int **array, int rows, int columns) {
    int* array_of_pointers = (int *)calloc(1, (sizeof(int) * rows));
    int* sorted_array = (int*)calloc(1,(sizeof(int) * rows* columns));
    int sorted_array_index = 0;

    while( sorted_array_index < (rows*columns) ) {
        int current_array = 0;
        while(array_of_pointers[current_array] >= columns) {
            current_array++;
        }

        int min_number = array[current_array][array_of_pointers[current_array]];
        int min_index = current_array;

        for (; current_array < rows; current_array++) {
            if (array_of_pointers[current_array] >= columns) {
                continue;
            }
            int number = array[current_array][array_of_pointers[current_array]];
            if ( number < min_number) {
                min_number = array[current_array][array_of_pointers[current_array]];
                min_index = current_array;
            }
        }
        array_of_pointers[min_index]++;
        sorted_array[sorted_array_index] = min_number;
        sorted_array_index++;
    }

    printf("\n After merging sorted Array elements are like below:\n");

    for ( int i = 0; i < sorted_array_index; i++) {
        printf("%d ",sorted_array[i]);
    }
}
void main() {
        int number_of_arrays;
        int number_of_elements_per_array;
        printf("Enter the Number of arrays:");
        scanf("%d",&number_of_arrays);
        printf("Enter the Number of elements per array:");
        scanf("%d",&number_of_elements_per_array);

        int** array_2D = (int **)malloc(number_of_arrays * sizeof(int*));

        for(int array=0; array<number_of_arrays; array++) {
            array_2D[array] = (int *) malloc (sizeof(int) * number_of_elements_per_array);
        }

        for(int row = 0; row < number_of_arrays; row++) {
            for(int column = 0; column < number_of_elements_per_array; column++) {
                printf("Enter Array[%d][%d] = ",row,column);
                scanf("%d",&(array_2D[row][column]));
            }
        }
        merge_k_sorted_array(array_2D,number_of_arrays,number_of_elements_per_array);
}
 