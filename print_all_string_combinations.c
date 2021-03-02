/******************************************************************************

Print all the combinations of a string
Note: Not permutations it is combinations.
for ex. if string is "ABC" 
combinations are: [] [A] [B] [C] [AB] [AC] [BC] [ABC]
Explaination to this algorithm is at GeeksForGeeks!
link: https://practice.geeksforgeeks.org/tracks/DSASP-Recursion/?batchId=154
Question Name: Generate Subsets
*******************************************************************************/

#include <stdio.h>
void print_combinations(char* string, char* curr, int curr_index);

int main()
{
    char string[32] = {};
    char empty_string[32] = {};
    printf("Enter string: ");
    scanf("%s",string);
    print_combinations(string, empty_string, 0);
    return 0;
}
void print_combinations(char* string, char* curr, int curr_index) {
    if (curr_index == strlen(string)) {
        printf("[%s]", curr);
        return;
    } else {
        print_combinations(string, curr, curr_index+1);
        string_append(curr, string[curr_index]);
        print_combinations(string, curr, curr_index+1);
        string_append_remove(curr, string[curr_index]);
    }
}

void string_append(char* string, char* append){
    string[strlen(string)] = append;
    string[strlen(string) + 1] = 0;
}
void string_append_remove(char* string, char* append){
    string[strlen(string) - 1] = 0;
}
