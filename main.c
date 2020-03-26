#include <stdio.h>
#include <stdlib.h>

int count_of_nodes = 0;
typedef struct st
{
    int data;
    struct st *next;
}node;

node *hptr = NULL;
node *last = NULL;

void sort_ll()
{
    int i,j;
    for(i=0;i<(count_of_nodes-1);i++)
    {
        node *temp = hptr;
        for(j=0;j<(count_of_nodes-i-1);j++)
        {
            if((temp->data) > (temp->next)->data)
            {
                int var = temp->data;
                temp->data = (temp->next)->data;
                (temp->next)->data = var;
            }
            temp = temp->next;
        }
    }
}
void add()
{
    int number;
    printf("Enter the number to be added: ");
    scanf("%d",&number);
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = number;
    if(hptr == NULL)
        hptr = temp;
    else
         last->next = temp;
    last= temp;
    count_of_nodes++;
}
void print()
{
    if(hptr == NULL)
    {
        printf("Linked list empty!\n");
        return;
    }
    node *temp = hptr;
    while(temp)
    {
        printf("-|%d|-",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    char ch;
    do{
        add();
        printf("Do you want to add more (Y/N)?:");
        scanf(" %c",&ch);
    }while(ch == 'Y'|| ch == 'y');
    print();
    sort_ll();
    print();
    delete_same_elements();
    print();
    reverse_ll();
    printf("Reversed linked list:\n");
    print();
    return 0;
}
void delete_same_elements()
{
    node* temp = hptr;
    node* prev = NULL;
next:
    while(temp)
    {
        if(temp->next != NULL)
        {
            if(temp->data == (temp->next)->data)
            {
                while((temp->next)&&(temp->data == (temp->next)->data))
                {
                    delete_node(temp,temp->next);
                }
                node * safeside = temp->next;
                delete_node(prev,temp);
                temp = safeside;
                goto next;
            }
        }
        if (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        else
        {
            hptr = temp;
            break;
        }
    }
}
void delete_node(node* prev_node,node* node_to_be_deleted)
{
    if(prev_node == NULL)
    {
        hptr = node_to_be_deleted->next;
        free(node_to_be_deleted);
        node_to_be_deleted = NULL;
    }
    else
    {
        prev_node->next = node_to_be_deleted->next;
        free(node_to_be_deleted);
        node_to_be_deleted = NULL;
    }
    return;
}
void reverse_ll()
{
    if(hptr == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    node *temp = hptr;
    node *prev = NULL;
    node *next = temp->next;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    hptr = prev;
}
void reverse_ll_no()
{
    int group_of;
    bool hptr_updated = false;
    printf("Enter number of groups you want to reverse!\n");
    scanf("%d",&group_of);
    if(hptr == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    node *temp = hptr;
    node *prev = NULL;
    node *next = temp->next;
again:
    count = group_of;
    node* end_of_prev_group = temp;
    while(temp&&count)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        count--;
    }
    if(!hptr_updated)
    {
        hptr = prev;
        hptr_updated = true;

    }
    if(count==0 && temp)
    {

        goto again:
    }
}
