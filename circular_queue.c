#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Options for User
*/
#define INIT    (0u)
#define ENQ     (1u)
#define DEQ     (2u)
#define DEL     (3u)
#define PRINT   (4u)
#define EXIT    (5u)

/**
 * @brief Structure to hold Queue elements
 * 
 */
typedef struct
{
    uint32_t *buffer;    /** Queue Buffer */
    uint8_t head;        /** Queue Front */
    uint8_t tail;        /** Queue Rear */
    uint8_t count;       /** Queue Current Count */
    uint8_t max_count;   /** Queue Max Count */
} c_queue;

/**
 * @brief Implements operation to initialize the queue
 * 
 * @param size      Size of the queue buffer elements
 * @return c_queue* Pointer to queue NULL if failed 
 */
c_queue* init_cqueue(uint8_t size)
{
    c_queue* temp_queue = NULL;
    if (size != 0)
    {
        uint32_t* temp          = (uint32_t*)malloc(size * sizeof(int));
        temp_queue              = (c_queue*)malloc(sizeof(c_queue));
        if ((temp != NULL) && (temp_queue != NULL))
        {
            temp_queue->head        = 0u;
            temp_queue->tail        = 0u;
            temp_queue->max_count   = size;
            temp_queue->count       = 0u;
            temp_queue->buffer      = temp;
        }
    }
    return temp_queue;
}

/**
 * @brief Deletes the queue
 * 
 * @param q_addr    Queue to be deleted
 * @return true     If deleted successfully
 * @return false    If failed to delete
 */
bool delete_queue(c_queue* q_addr)
{
    bool ret = false;

    if (q_addr != NULL)
    {
        free(q_addr->buffer);
        free(q_addr);
        ret = true;
    }
    
    return ret;
}

/**
 * @brief Checks if queue is full
 * 
 * @param q_addr    Address of the queue to be checked
 * @return true     Queue is full
 * @return false    Queue is not full
 */
bool isFull(c_queue* q_addr)
{
    return ((q_addr->count == q_addr->max_count) ? true : false);
}

/**
 * @brief Checks if queue is empty
 * 
 * @param q_addr    Address of the queue to be checked
 * @return true     Queue is empty
 * @return false    Queue is not empty
 */
bool isEmpty(c_queue* q_addr)
{
    return (q_addr->count == 0u ? true : false);
}

/**
 * @brief Adds element to the queue buffer
 * 
 * @param q_addr    queue address to be enqueued
 * @param data      data to be enqueued
 * @return true     data enqueued successfully
 * @return false    failed to enqueue data
 */
bool enqueue(c_queue* q_addr, int data)
{
    bool ret = false;

    if (!isFull(q_addr))
    {
        q_addr->buffer[q_addr->tail] = data;
        q_addr->tail = ((q_addr->tail + 1) == q_addr->max_count) ? 0u : (q_addr->tail + 1);
        q_addr->count++;
        ret = true;
    }

    return ret;
}

/**
 * @brief Removes element from the queue buffer
 * 
 * @param q_addr    queue address to be dequeued
 * @param data      data to be filled in after dequeue operation
 * @return true     data dequeued successfully
 * @return false    failed to dequeue data
 */
bool dequeue(c_queue* q_addr, int* data)
{
    bool ret = false;

    if (!isEmpty(q_addr) && (data != NULL))
    {
        *data = q_addr->buffer[q_addr->head];
        q_addr->buffer[q_addr->head] = 0u;
        q_addr->head = ((q_addr->head + 1) == q_addr->max_count) ? 0u : (q_addr->head + 1);
        q_addr->count--;
        ret = true;
    }

    return ret;
}

/**
 * @brief Prints the content of the queue buffer
 * 
 * @param q_addr 
 */
void print_queue(c_queue* q_addr)
{
    uint8_t i = 0u;
    
    printf("Printing Queue 0 to Max\n[");
    for (; i < q_addr->max_count ; i++)
    {
        printf(" %d " ,q_addr->buffer[i]);
    }
    printf("]\n");
}

int main()
{
    uint32_t option         = 0u;
    c_queue *temp_queue     = NULL;

    while(option != EXIT)
    {
        printf("Enter option [0.INIT 1.ENQ 2.DEQ 3.DEL 4.PRINT 5.EXIT] \n");
        scanf(" %d", &option);
        switch(option)
        {
            case INIT:
            {
                uint32_t size = 0u;
                printf("Enter the size of queue = ");
                scanf(" %d", &size);
                temp_queue = init_cqueue(size);
                if (temp_queue == NULL)
                {
                    printf("INIT_QUEUE operation failed!\n");
                }
                break;
            }
            
            case ENQ:
            {
                uint32_t data = 0u;
                printf("Enter the number you want to add = ");
                scanf(" %d", &data);
                if (!enqueue(temp_queue, data))
                {
                    printf("ENQUEUE operation failed\n");
                }
                else
                {
                    printf("ENQUEUE success! data = %d added\n", data);
                }
                break;                
            }

            case DEQ:
            {
                uint32_t data = 0u;
                if (!dequeue(temp_queue, &data))
                {
                    printf("DEQUEUE operation failed\n");
                }
                else
                {
                    printf("DEQUEUE success! data = %d\n", data);
                }
                break;
            }

            case DEL:
            {
                if (!delete_queue(temp_queue))
                {
                    printf("DEL_QUEUE operation failed\n");
                }
                break;                
            }
            
            case PRINT:
            {
                print_queue(temp_queue);
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
