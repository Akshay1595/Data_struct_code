#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * Options for User
*/
#define ENQ     (1u)
#define DEQ     (2u)
#define PRINT   (3u)
#define EXIT    (5u)

typedef struct node_t
{
    int data;
    struct node_t* next;
} cq_node;

void print_cq(cq_node* head)
{
    if (head)
    {
        cq_node* temp = head;
        printf("%d ", temp->data);
        temp = temp->next;

        while (temp != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

cq_node* en_queue(cq_node* head, int data)
{
    cq_node * temp = (cq_node *)malloc(sizeof(cq_node));

    if (head == NULL)
    {
        temp->data = data;
        head = temp->next = temp;
    }
    else
    {
        temp->data = head->data;
        head->data = data;
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
}

cq_node* de_queue(cq_node* head, int *data)
{
    if (head)
    {
        *data = head->data;

        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            cq_node * node_tbd = head->next;
            head->data = node_tbd->data;
            head->next = node_tbd->next;
            free(node_tbd);
        }
    }
    else
    {
        printf("CQ empty!\n");
    }
    return head;
}

int main()
{
    uint32_t option = 0u;
    cq_node* head   = NULL;

    while(option != EXIT)
    {
        printf("Enter option [1.ENQ 2.DEQ 3.PRINT 5.EXIT] \n");
        scanf(" %d", &option);
        switch(option)
        {   
            case ENQ:
            {
                uint32_t data = 0u;
                printf("Enter the number you want to add = ");
                scanf(" %d", &data);
                head = en_queue(head, data);
                break;                
            }

            case DEQ:
            {
                int32_t data = 0u;
                head = de_queue(head, &data);
                break;
            }
            
            case PRINT:
            {
                print_cq(head);
                break;         
            }

            default:
            {
                printf("Bye Bye ! \n");
                break;                
            }

        }
    }

    return 0;
}