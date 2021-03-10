#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

extern bst_node* head_root;

bst_node* findMin(bst_node* root) {
    bst_node* temp = root;
    while (temp->left)
        temp = temp->left;
    return temp;
}
static bst_node* findMax(bst_node* root) {
    bst_node* temp = root;
    while (temp->right)
        temp = temp->right;
    return temp;
}

bst_node* bst_delete_node(bst_node* root, int number) {
    if (root == NULL)
        return root;
    else if (number < root->data){
        root->left = bst_delete_node(root->left, number);
    }else if (number > root->data) {
        root->right = bst_delete_node(root->right, number);
    }else if (number == root->data) {
        //case 1:
        if ((root->left == NULL) && (root->right == NULL)) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) { //case 2
            bst_node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            bst_node* temp = root;
            root = root->left;
            free(temp);
        } else { //case 3
            // one way to do 
            bst_node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = bst_delete_node(root->right, temp->data);
            // other way to do
            /*
            bst_node* temp = findMax(root->left);
            root->data = temp->data;
            root->left = bst_delete_node(root->left, temp->data);            
            */
        }
    }
    return root;
}

bst_node* bst_insert_node(bst_node* root, int number) {
    if (root == NULL) {
        bst_node* temp = (bst_node*)malloc(sizeof(bst_node));
        temp->data = number;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (number < root->data) 
        root->left = bst_insert_node(root->left,  number);
    else
        root->right = bst_insert_node(root->right, number);
    return root;
}

void bst_print(bst_node* root,const int order_type) {

    if (root) {
        //printf("\nInside print with root = %u\n", root->data);
        if (order_type == INORDER) {
            bst_print(root->left, order_type);
            printf("-| %d |-", root->data);
            bst_print(root->right, order_type);
        }else if (order_type == PREORDER) {
            printf("-| %d |-", root->data);
            bst_print(root->left, order_type);
            bst_print(root->right, order_type);
        }else {
            bst_print(root->left, order_type);
            bst_print(root->right, order_type);
            printf("-| %d |-", root->data);
        }
    }
}