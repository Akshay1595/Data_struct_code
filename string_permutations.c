/******************************************************************************

Print all the permutations of string
For ex. "ABC"
[ ABC, ACB, BAC, BCA, CBA, CAB] 
Link for referrence: https://www.youtube.com/watch?v=GuTPwotSdYw&t
*******************************************************************************/

#include <stdio.h>

void swap(char* ch1, char* ch2){
    char temp;
    temp = *ch2;
    *ch2 = *ch1;
    *ch1 = temp;
}

void permute(char* string, int left, int right);

int main()
{
    char string[32] = {};
    printf("Enter the string: ");
    scanf("%s",string);
    permute(string, 0, (strlen(string)-1));
    return 0;
}

void permute(char* string, int left, int right) {
    if (left >= right) {
        printf("%s ", string);
        return;
    }else{
        for (int i=left; i <= right; i++) {
            swap((string+left), (string+i));
            permute(string, left+1, right);
            swap((string+left), (string+i));
        }
    }
}
