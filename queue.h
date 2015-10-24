
typedef struct node {
	int num;
	struct node *next;
}node;

typedef struct queue {
	struct node *front;
}queue;

void qinit(queue *q);
int qempty(queue *q);
int qfull(queue *q); 
void enqueue(queue *q, int num);
int dequeue(queue *q);
