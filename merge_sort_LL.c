#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add below macro to debug the code
//#define DEBUG

typedef struct node_t
{
    int data;
    struct node_t *next;
} node;

node* find_middle_node(node* head);

void print_ll(node * head)
{
    node* temp = head;
    while(temp)
    {
        printf("-|%d|-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node * create_ll(void)
{
    node *head = NULL, *last = NULL;
    int num_of_elements = 0;
    int i = 0;
    int data = 0;

    printf("[%s] Enter the number of nodes you want to add = ", __func__);
    scanf(" %d", &num_of_elements);

    while (i < num_of_elements)
    {
        printf("Data at the node[%d] = ", i);
        scanf(" %d", &data);

        node * temp = (node *)malloc(sizeof (node));

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            last->next = temp;
        }
        temp->data = data;
        temp->next = NULL;
        last = temp;
        i++;
    }

    printf("[%s] Linked List created looks like: \n", __func__);
    print_ll(head);
    return head;
}

node* merge_ll(node* head1, node* head2)
{
    node* result_head = NULL;
    node* temp1 = head1;
    node* temp2 = head2;
    node* last = NULL;

    if (head1 == NULL)
    {
        result_head = head2;
#ifdef DEBUG
        printf("[%s] head1 = NULL\n", __func__);
#endif /* DEBUG */
    }
    else if (head2 == NULL)
    {
        result_head = head1;
#ifdef DEBUG
        printf("[%s][%d] head2 = NULL\n", __func__, __LINE__);
#endif /* DEBUG */
    }
    else
    {
#ifdef DEBUG
        printf("[%s][%d] head1 = %d head2 = %d\n", __func__, __LINE__, head1->data, head2->data);
#endif /* DEBUG */

        /* Mark Head condition */
        if (temp1->data < temp2->data)
        {
            last = result_head = temp1;
            temp1 = temp1->next;
        }
        else
        {
            last = result_head = temp2;
            temp2 = temp2->next;
        }

        /* Start checking for new one */
        while(temp1 && temp2)
        {
#ifdef DEBUG
            printf("[%s][%d] t1 = %d t2 = %d\n", __func__, __LINE__, temp1->data, temp2->data);
#endif /* DEBUG */

            if (temp1->data < temp2->data)
            {
                last->next = temp1;
                last = temp1;
                temp1 = temp1->next;
#ifdef DEBUG
                printf("[%s][%d] t1 < t2\n", __func__, __LINE__);
#endif /* DEBUG */
            }
            else
            {
                last->next = temp2;
                last = temp2;
                temp2 = temp2->next;
#ifdef DEBUG
                printf("[%s][%d] t2 < t1\n", __func__, __LINE__);
#endif /* DEBUG */
            }
        }
        if (temp1 == NULL)
        {
            last->next = temp2;
        }
        else if (temp2 == NULL)
        {
            last->next = temp1;
        }
    }
    return result_head;
}

node* merge_sort_ll(node* head)
{
    node *result = head;

    if ((head == NULL) || (head->next == NULL))
        return result;

    node* mid = find_middle_node(head);
#ifdef DEBUG
    if (mid != NULL)
        printf("[%s] mid node = %d\n", __func__, mid->data);
#endif /* DEBUG */

    node* left_head  = head;
    node* right_head = mid->next;

    mid->next = NULL;

#ifdef DEBUG
    printf("[%s] Left LL:\n", __func__);
    print_ll(left_head);
    printf("[%s] Right LL:\n", __func__);
    print_ll(right_head);
#endif /* DEBUG */

    left_head  = merge_sort_ll(left_head);
    right_head = merge_sort_ll(right_head);
    head = merge_ll(left_head, right_head);
#ifdef DEBUG
    printf("[%s] After merging left LL and Right LL:\n", __func__);
    print_ll(head);
#endif /* DEBUG */

    return head;
}

node* find_middle_node(node* head)
{
    node * t1 = head;
    node * t2 = head;

    if (t1 != NULL)
    {
        while(t2->next && (t2->next)->next)
        {
            t1 = t1->next;
            t2 = (t2->next)->next;
        }
    }
    return t1;
}

int main()
{
    node* head1 = create_ll();
    //printf("Middle Node of LL1 = %d\n", (find_middle_node(head1))->data);
    head1 = merge_sort_ll(head1);
    printf("[%s] After Sorting: \n", __func__);
    print_ll(head1);

    node* head2 = create_ll();
    //printf("Middle Node of LL2 = %d\n", (find_middle_node(head2))->data);
    head2 = merge_sort_ll(head2);
    printf("[%s] After Sorting: \n", __func__);
    print_ll(head2);

    node* merged_ll = merge_ll(head1, head2);
    print_ll(merged_ll);

    return 0;
}