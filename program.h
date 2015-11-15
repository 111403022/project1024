
/*Linked List is used in Seat Selection*/
typedef struct node {
	char *str;
	struct node *next;
}node;

typedef struct list {
	struct node *front, *rear;
	int length;
}list;

/*Queue is used in Booking Confirmation*/
typedef struct node1 {
	char *data;
	struct node1 *next;
}node1;

typedef struct queue {
	node1 *head, *tail;
}queue;

void init(list *l);
void Show_Seats(list *l);
void Seat_Availability(list *l, char *str);
char *Seat_Selection(list *l, int pos);
int lempty(list *l);
void qinit(queue *q);
void enqueue(queue *q, char *name);
char *dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q);
void qprint(queue *q);
