#include <stdio.h>
#include "cqueue_struct.h"

int is_fifo_empty(fifo* user_fifo)
{
    return((user_fifo->head == -1) && (user_fifo->tail == -1));
}
int is_fifo_full(fifo* user_fifo)
{
    int status = 0;
    if(user_fifo->tail > user_fifo->head)
    {
        if((user_fifo->tail - user_fifo->head) == MAX-1)
            status = 1;
        else
            status = 0;
    }
    else
    {
        if((user_fifo->head - user_fifo->tail) == 1)
            status = 1;
        else
            status = 0;
    }
    return status;
}

void fifo_init(fifo* user_fifo)
{
    user_fifo->head = -1;
    user_fifo->tail = -1;
}

void add_node(fifo* user_fifo,int data)
{
    if(is_fifo_full(user_fifo))
    {
        printf("Queue full bro!\n");
        return;
    }

    if(is_fifo_empty(user_fifo))
    {
        /*if queue was empty
        take necessary care while adding first node
        indicating there is only one node
        */
        user_fifo->head = user_fifo->tail = 0;
    }
    else if(user_fifo->tail == MAX-1)
        user_fifo->tail = 0;
    else
        user_fifo->tail++;
    user_fifo->queue[user_fifo->tail] = data;
}

int delete_node(fifo* user_fifo)
{
    if(is_fifo_empty(user_fifo))
    {
        printf("Queue Empty!\n");
        return 0;
    }
    int number_to_be_deleted;
    number_to_be_deleted = user_fifo->queue[user_fifo->head];
    user_fifo->queue[user_fifo->head] = 0;

    if (user_fifo->head == user_fifo->tail)
    {
        user_fifo->head = user_fifo->tail = -1;
        return number_to_be_deleted;
    }
    if(user_fifo->head == MAX-1)
        user_fifo->head = 0;
    else
        user_fifo->head++;

    return number_to_be_deleted;
}

void print(fifo* user_fifo)
{
    if(is_fifo_empty(user_fifo))
    {
        printf("Queue is empty bro!\n");
        return;
    }
    int i = user_fifo->head;
    while(i != user_fifo->tail)
    {
        printf("%d ",user_fifo->queue[i]);
        i++;
        if(i == MAX)
            i = 0;
    }
    printf("%d \n",user_fifo->queue[i]);
}

void main()
{
    fifo fifo_1;
    fifo_init(&fifo_1);
    int num;
    int deleted_element;
    int choice;
    printf("Hello World!\n");
    while(1)
    {
        printf("Enter choice: 1 - add\t2 - delete\t3 - print\t any - exit : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case ADD_NODE:
                printf("Enter number to be added:");
                scanf("%d",&num);
                add_node(&fifo_1,num);
                break;

            case DEL_NODE:
                delete_node(&fifo_1);
                break;

            case PRINT:
                print(&fifo_1);
                break;

            default:
                goto out;
                break;
        }
    }
out:
    printf("Bye bye!\n");
    return 0;
}
