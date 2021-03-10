#ifndef BST_H
#define BST_H

#define INORDER     (0)
#define PREORDER    (1)
#define POSTORDER   (2)

typedef struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
}bst_node;

extern bst_node* findMin(bst_node* root);
extern bst_node* bst_insert_node(bst_node*  root_node, int number);
extern bst_node* bst_delete_node(bst_node* root, int number);
extern void bst_print(bst_node* root_node,const int order_type);

#endif