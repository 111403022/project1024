#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
void qinit(queue *q) {
	q->front = NULL;
}
int qempty(queue *q) {
	return q->front == NULL;
}
int qfull(queue *q) { 
	return 0;
}
void enqueue(queue *q, int num) {
	struct node *temp, *temp1;
	temp1 = (node *)malloc(sizeof(node));		
	if(q->front == NULL) {
		temp1->num = num;
		temp1->next = NULL;	
		q->front = temp1;	
	}
	else {
		temp = q->front;
		while(temp->next != NULL)
			temp  = temp->next;
		temp->next = temp1;
		temp1->num= num;
		temp1->next = NULL;
	}	
}

int dequeue(queue *q) {
	char ch = q->front->num;
	node *temp = q->front->next;
	free(q->front);
	q->front = temp;
	if(q->front == NULL)
		;
	return ch;
}
void qprint(queue *q) {
	struct node *temp = q->front;
	if(q->front != NULL) {
		while(temp->next !=NULL) {
			printf("%d ", temp->num);
			temp = temp->next;			
		}
	printf("%d ", temp->num);
	}
}
