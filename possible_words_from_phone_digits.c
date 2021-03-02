/******************************************************************************

Q. Possible Words From Phone Digits

Given a keypad as shown in the diagram,
and an N digit number which is represented by array a[ ],
the task is to list all words which are possible by pressing these numbers.

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define NUMBER_OF_ELEMENTS      (3)

void print_numbers(int *array, int number_of_elements, int number, char* string);

char hasharray[10][5] = {
    "0",    //0
    "1",    //1
    "abc",  //2
    "def",  //3
    "ghi",  //4
    "jkl",  //5
    "mno",  //6
    "pqrs", //7
    "tuv",  //8
    "wxyz"  //9
};

int main() {
    int array[NUMBER_OF_ELEMENTS] = { 4, 2, 3 };
    char string[NUMBER_OF_ELEMENTS+1] = {};
    print_numbers(array, 3, 0, string);
    return 0;
}

void print_numbers(int* array, int number_of_elements, int num_index, char* string) {
    //printf(" num_index = %d string = %s\n", num_index, string);
    if ( num_index == number_of_elements ) {
        string[num_index] = 0;
        printf("%s ", string);
        return;
    } else {
        for (int i=0; hasharray[(array[num_index])][i]; i++) {
            //printf(" i = %d char = %c\n", i, hasharray[(array[num_index])+1][i] );
            string[num_index] = hasharray[(array[num_index])][i];
            print_numbers(array, number_of_elements, (num_index+1), string);
        }
        printf("\n");
    }
}
