#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "program.h"

void init(list *l) {

	l->front = l->rear = NULL;
	l->length = 0;

}

/*This function shows seats*/
void Show_Seats(list *l) {
	
	int i = 1;
	int pos = 1;
	printf("\nSeats Available:\n");
	node *ptr = l->front;

	while(ptr != l->rear) {
		while(pos <= 286) {
			if(pos == 16)
				printf("\n");
			else if (pos == 31)
				printf("\n");
			else if(pos == 46)
				printf("\n");
			else if(pos == 61)
				printf("\n");
			else if(pos == 76)
				printf("\n");
			else if(pos == 91)
				printf("\n");
			else if(pos == 106)
				printf("\n");
			else if(pos == 121)
				printf("\n");
			else if(pos == 136)
				printf("\n");
			printf("%3d. %s ", pos, ptr->str);
			i++;
			pos++;
			break;
		}	
		ptr = ptr->next;
	}	
	printf("\n");

}

/*This function shows seats available*/
void Seat_Availability(list *l, char *str) {

	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->str = (char *)malloc(strlen(str) + 1);
	strcpy(temp->str, str);
	if(l->front == NULL) {
		temp->next = l->front = l->rear = temp;
		l->length = 1;
		return;
	}
	l->rear->next = temp;
	l->rear = temp;
	(l->length)++;	

}

/*This function select seats available*/
char *Seat_Selection(list *l, int pos) {

	node *temp, *ptr;
	int i;
	if(pos < 0 || pos > l->length)		
		return 0;
	temp = (node *)malloc(sizeof(node));
	ptr = l->front;
	if(pos == 0) {
		temp = l->front;
		l->front = ptr->next;		
		//ptr->next == NULL;

	}
	for(i = 0; i < pos - 1; i++){
		ptr = ptr->next;
	}
	if(pos > 0 && pos < l->length) {
		temp = ptr->next;
		ptr->next = temp->next;	

	}
	if(pos == l->length - 1) {
		temp = l->rear; 
		l->rear = ptr->next;
		//ptr->next == NULL;
		return 0;
	}
	(l->length)--;
	return(temp->str);
	free(temp);

}

int lempty(list *l) {

	if(l->front == NULL)
		return 1;
	return 0;

}

int lfull(list *l) { 

	return 0;

}

/*Queue is used in function Booking_confirmation()*/
void qinit(queue *q) {

	q->head = NULL;
	q->tail = NULL;

}

void enqueue(queue *q, char *name) {

	node1 *tmp;
	tmp = (node1 *)malloc(sizeof(node1));
	tmp->data = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->data, name);	
	tmp->next = NULL;
	
	if(q->tail == NULL) 
		q->head = tmp;
	else
		q->tail->next = tmp;
	q->tail = tmp;

}

char *dequeue(queue *q) {

	node1 *tmp = q->head->next;
	char *retdata = q->head->data;
	free(q->head);
	q->head = tmp;
	if(q->head == NULL)
		q->tail = NULL;
	return retdata;

}

int qempty(queue *q) {

	if(q->head == NULL)
		return 1;
	return 0;

}

int qfull(queue *q) { 

	return 0;

}

void qprint(queue *q) {

	node1 *tmp = q->head;
	while(tmp) {
		printf("%s ", tmp->data);
		tmp = tmp->next;
	}
	printf(" \n");

}
