/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define ADD_NODE 1
#define DEL_NODE 2
#define PRINT 3
#define MAX 5

int head = -1;
int tail = -1;
int c_queue[MAX] = {};

int queue_empty()
{
    return((head == -1) && (tail == -1));
}
int queue_full()
{
    if(tail > head)
    {
        if(tail-head == MAX-1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(head-tail == 1)
            return 1;
        else
            return 0;
    }
}

void print()
{
    if(queue_empty())
    {
        printf("Queue is empty bro!\n");
        return;
    }
    int i = head;
    while(i != tail)
    {
        printf("%d ",c_queue[i]);
        i++;
        if(i == MAX)
        {
            i = 0;
        }
    }
    printf("%d \n",c_queue[i]);
}

void add_node()
{
    if(queue_full())
    {
        printf("Queue full bro!\n");
        return;
    }
    int num;
    printf("Enter number to be added : ");
    scanf("%d",&num);

    if(queue_empty())
    {
        /*if queue was empty
        take necessary care while adding first node
        indicating there is only one node
        */
        printf("Since queue is empty adding to first node\n");
        head = tail = 0;
        c_queue[tail] = num;
        return;
    }
    if(tail == MAX-1)
        tail = 0;
    else
        tail++;
    c_queue[tail] = num;
}

void delete_node()
{
    if(queue_empty())
    {
        printf("Queue empty bro!\n");
        return;
    }
    c_queue[head] = 0;

    /* you had only one node which is shown with
    head = tail
    and you had deled that node too!
    which means queue is empty now!
    hence marking
    head = tail = -1
    */
    if (head == tail)
    {
        head = tail = -1;
        return;
    }
    if(head == MAX-1)
        head = 0;
    else
        head++;
}


int main()
{
    int choice;
    printf("Hello World!\n");
    while(1)
    {
        printf("Enter choice: 1 - add\t2 - delete\t3 - print\t any - exit : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case ADD_NODE:
                add_node();
                break;
            case DEL_NODE:
                delete_node();
                break;
            case PRINT:
                print();
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
