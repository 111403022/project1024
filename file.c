#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
void bookinginstruction() {
}
void printmenu() {
	printf("\n");
	printf("1. To see the seats available\n");
	printf("2. Select row\n");
	printf("3. Select seats\n");
	printf("4. Seats Booked\n");
	printf("5. Exit\n");
}
void Audi_Layout() {
	FILE *fp;
	char c;
	fp = fopen("l.txt", "r");
	while((c = getc(fp)) != EOF)		
	printf("%c", c);
	fclose(fp);
}
void row_selection(char row) {	
	if(row >= 'A' && row <= 'S') {
		printf("Row selected is %c\n", row);			
	}
	else {
		printf("INVALID!\n");
	}
}
int main() {
	char r;
	int n;
	int choice;
	queue q;
	qinit(&q);
	while(1) {
		qprint(&q);
		printmenu();	
		scanf("%d", &choice);		
		switch(choice) {		
			case 1:/*Audi_Layout*/
				Audi_Layout(); 
				break;
			case 2:/*Row_Selection*/
				printf("Select row: ");	
				getchar();			
				scanf("%c", &r);
				row_selection(r);
				break;
			case 3:/*Selecting_Seat*/
				printf("Select seats and press Ctrl+d.\n");
				if(!qfull(&q)) {										
					while (scanf("%d", &n) != -1) {
						if(n < 1 || n > 15) {
							printf("INVALID!\n");
						}
						else {					
						enqueue(&q, n);
						}
					}
				}	
					else {
					printf("Housefull\n");
					continue;
				}
				break;
			case 4:/*Booking_Confirmation*/
				if(!qempty(&q)) {
					printf("Seats booked are\n");
					n = dequeue(&q);
					printf("%c %d ", r, n);					
				}
				else {
					printf("No seats\n");
					continue;
				}				
				break;
			case 5:/*Exit*/
				return 0;
			default:
				break;
		}
	}
	return 0;
}
