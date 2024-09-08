#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//Add below macro if you want to see detailed prints
//#define DEBUG

void merge_sort(int *array, int n);
void merge(int *left_array, int n_left, int *right_array, int n_right, int * array);
void print_array(int *array, int n);

void print_array(int *array, int n)
{
    int i = 0;
    for ( ; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int num_of_elements = 0;
    int *array = NULL;

    printf("[%s] Enter the number of elements in array = ", __func__);
    scanf(" %d", &num_of_elements);

    array = (int*)malloc(num_of_elements * sizeof(int));

    for(int i = 0; i < num_of_elements; i++)
    {
        printf("array[%d] = ", i);
        scanf(" %d", &array[i]);
    }
    
    printf("[%s] Before Sort: \n", __func__);
    print_array(array, num_of_elements);

    merge_sort(array, num_of_elements);

    printf("[%s] After Sort: \n", __func__);
    print_array(array, num_of_elements);
    return 0;
}


void merge(int *left_array, int n_left, int *right_array, int n_right, int * array)
{
    int i = 0u, j = 0u, k = 0u;

#ifdef DEBUG
    printf("[%s] n_left = %d n_right = %d\n", __func__, n_left, n_right);
    printf("[%s] Before merge array:\n", __func__);   
    print_array(array, n_left + n_right);
#endif /* DEBUG */

    while((i < n_left) && (j < n_right))
    {
        if (left_array[i] < right_array[j])
        {
            array[k++] = left_array[i++];
        }
        else
        {
            array[k++] = right_array[j++];
        }
    }
    while(i < n_left)
    {
        array[k++] = left_array[i++];
    }
    while (j < n_right)
    {
        array[k++] = right_array[j++];
    }
}

void merge_sort(int *array, int n)
{
    int mid = 0u;
    int n_left = 0, n_right = 0;
    int *left_array = NULL;
    int *right_array = NULL;
    int i = 0;
    int j = 0;

    if (n > 1)
    {
        mid = n/2;
#ifdef DEBUG
        printf("[%s] n = %d mid = %d array[0] = %d \n", __func__, n, mid, array[0]);
#endif /* DEBUG */ 
        n_left = mid; 
        n_right = n - mid;
        left_array  = (int *)malloc(n_left  * sizeof(int));
        right_array = (int *)malloc(n_right * sizeof(int));
        for (; i < n_left; i++)
        {
            left_array[i] = array[i];
        }
        j = 0;
        for (; i < n; i++, j++)
        {
            right_array[j] = array[i]; 
        }
#ifdef DEBUG
        printf("[%s] Left_array = \n", __func__);
        print_array(left_array, n_left);
        printf("[%s] right_array = \n", __func__);
        print_array(right_array, n_right);
#endif /* DEBUG */
        merge_sort(left_array, n_left);
        merge_sort(right_array, n_right);
        merge(left_array, n_left, right_array, n_right, array);
#ifdef DEBUG
        printf("[%s] After merging left and right array: \n", __func__);
        print_array(array, n);
#endif /* DEBUG */
        free(left_array);
        free(right_array);
    }
}