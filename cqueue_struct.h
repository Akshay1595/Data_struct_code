#define MAX 5
#define ADD_NODE 1
#define DEL_NODE 2
#define PRINT 3

typedef struct cqueue{
    int queue[MAX];
    int head;
    int tail;
}fifo;

int is_fifo_empty(fifo* user_fifo);
int is_fifo_full(fifo* user_fifo);
void fifo_init(fifo* user_fifo);
void add_node(fifo* user_fifo,int data);
int delete_node(fifo* user_fifo);
void print(fifo* user_fifo);
