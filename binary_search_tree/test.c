#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_node* head_root = NULL;

void main() {
    int array[4] = {8, 4, 6, 12};
    for (int i = 0; i<4; i++) {
        head_root = bst_insert_node(head_root, array[i]);
    }
    printf("Updated Tree formed as :\n");
    bst_print(head_root, INORDER);

    int min1, min2;
    while (head_root->left && head_root->right) {
        min1 = findMin(head_root);
        head_root = bst_delete_node(head_root, min1);
        printf("\nUpdated Tree formed as :\n");
        bst_print(head_root, INORDER);

        min2 = findMin(head_root);
        head_root = bst_delete_node(head_root, min2);
        printf("\nUpdated Tree formed as :\n");
        bst_print(head_root, INORDER);

        head_root = bst_insert_node(head_root, (min1+min2));
        printf("\nUpdated Tree formed as :\n");
        bst_print(head_root, INORDER);
    }    
    
}