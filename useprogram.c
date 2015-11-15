/*****************************************************************************
 * Copyright (C) Apurva Baburao Madke   madkeab14.comp@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "program.h"

list p;
int class;
int time;

/*Prints the classes available on the screen*/
int printmenu() {

	int choice1;		
	printf("WELCOME TO DRAMAHALL PUNE\n");
	printf("\n");
	printf("Royal		Rs.300\n");
	printf("Platinum	Rs.200\n");
	printf("Gold 		Rs.150\n");
	printf("Silver 		Rs.100\n");
	printf("\n1. Proceed\n");
	scanf("%d", &choice1);
	if(choice1 == 1) {
		return choice1;	
	}
	else {
		printf("INVALID!\n");
		printmenu();	
	}
	return 0;
}

/*Prints the layout of the audi on screen*/
void Audilayout() {

	FILE *fp;
	char c;
	fp = fopen("l.txt", "r");
	while((c = getc(fp)) != EOF)		
		printf("%c", c);
	fclose(fp);

}

void royal() {

	FILE *fp;
	char c;
	fp = fopen("r1.txt", "r");
	while((c = getc(fp)) != EOF)		
		printf("%c", c);
	fclose(fp);

}

void platinum() {

	FILE *fp;
	char c;
	fp = fopen("p1.txt", "r");
	while((c = getc(fp)) != EOF)		
		printf("%c", c);
	fclose(fp);

}

void gold() {

	FILE *fp;
	char c;
	fp = fopen("g1.txt", "r");
	while((c = getc(fp)) != EOF)		
		printf("%c", c);
	fclose(fp);

}

void silver() {

	FILE *fp;
	char c;
	fp = fopen("s1.txt", "r");
	while((c = getc(fp)) != EOF)		
		printf("%c", c);
	fclose(fp);

}

/*This function is to select class*/
int select_class() {
			
	printf("\n");
	printf("Classes Available\n");
	printf("1. Royal\n");
	printf("2. Platinum\n");
	printf("3. Gold\n");
	printf("4. Silver\n");
	scanf("%d", &class);	
	
	if(class == 1) {
		royal();
	}
	else if(class == 2) {
		platinum();
	}
	else if(class == 3) {
		gold();
	}
	else if(class == 4) {
		silver();
	}
	return class;

}

/*This function is to show timings available and select time slot*/
int show_timing() {

	printf("\n");
	printf("Show Timings\n");
	printf("1.12:00 pm\n");
	printf("2.3:00 pm\n");
	printf("3.6:00 pm\n");
	printf("4.9:00 pm\n");
	scanf("%d", &time);
	
	return time;

}

/*This function is to confirm class selected*/
int class_confirm() {

	
	int  x, n, i;
	i = 0;
	struct data {
		int no;
		char info[16];

	}data[16];
	int fd = open("class", O_RDONLY);
	if(fd == -1) {
		perror("open failed:");
		return errno;
	}
	x = read(fd, &data, sizeof(data));
	n = x / sizeof(data[0]);
	for(i = 0; i < n; i++) {
		if(class == data[i].no) {
			printf("\nClass Selected is %s\n", data[i].info);
		}
	}
	close(fd);
	return 0;

}

/*This function is to confirm time selected*/
int time_confirm() {

	int x, n, i = 0;
	struct data {
		int no;
		char info[16];

	}data[16];
	int fd = open("time", O_RDONLY);
	if(fd == -1) {
		perror("open failed:");
		return errno;
	}
	x = read(fd, &data, sizeof(data));
	n = x / sizeof(data[0]);
	for(i = 0; i < n; i++) {
		if(time == data[i].no) {
			printf("Time Selected is %s\n", data[i].info);
		}
	}	
	close(fd);
	return 0;

}

/*This function is to enter number of tickets*/
int no_tickets() {
	
	int no;
	printf("\n\nNo. of tickets: ");
	scanf("%d", &no);
	return no;

}

/*This function is to confirm booking*/
void Booking_confirmation() {

	FILE *fp;
	fp = fopen("seats.txt", "r");
	char name[16], *n, c;
	int choice;
	queue q;
	qinit(&q);
	printf("\n");
	if(!qfull(&q)) {
		printf("\n");
		printf("Seats Selected are ");
		while((c = getc(fp) != EOF)) {
			fscanf(fp, "%s", name);
			enqueue(&q, name);
		}
		fclose(fp);
	} 
 	while(1) {
		qprint(&q);
		printf("\n");
		printf("1. To confirm booking\n");
		scanf("%d", &choice);
		switch(choice) {				
			case 1:
				printf("\n");
				printf("-----------------------Booking Info----------------------");
				printf("\nTicket booked are ");
				while(!qempty(&q)) {
					n = dequeue(&q);
					printf("%s ", n);
					free(n);
				}
				class_confirm();
				time_confirm();
				printf("\n");
				exit(0);
				break;
			default:
				break;
		}
	}
}

/*This function is to select seats*/
void select_seats() {

	FILE *f1; 
	char *s;	
	int pos1;
	int choice2;	
	int no, n = 0;
	no = no_tickets();
	f1 = fopen("seats.txt", "w");
	printf("\n1. Proceed\n");

	while(1) {
		scanf("%d", &choice2);		
		switch(choice2){
			case 1:
				printf("\n");
				if(!lempty(&p)) {
					while(n < no) {
						printf("\nSelect Seat Position: ");
						scanf("%d", &pos1);
						pos1--;
						s = Seat_Selection(&p, pos1);		
						fprintf(f1, " %s", s);
						printf("\nSeat selected is %s \n", s);
						free(s);
						Show_Seats(&p);
						n++;
					}
				fclose(f1);
				}
				else {
					printf("No Seats\n");		
					continue;
				}
				break;

			default:
				break;

		}

	Booking_confirmation();

	}

} 

/*This is the Main function*/
int main() {

	int choice1;
	choice1 = printmenu();		
	switch(choice1) {
		case 1:
			Audilayout();
			break;
		default:
			break;

	}
	
	int time;	
	init(&p);	
	char str[1024];
	FILE *fp;	
	char c;
	int class;
	class = select_class();
	switch(class) {
		case 1:/*Royal*/
			time = show_timing();
			switch(time) {
				case 1:/*12:00pm*/							
				fp = fopen("r.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);			
				select_seats();				
				break;	
				
			case 2:/*3:00pm*/
				fp = fopen("r.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
				
			case 3:/*6:00pm*/
				fp = fopen("r.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;

			case 4:/*9:00pm*/
				fp = fopen("r.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
			
			default:
				break;
			}
			break;
		case 2:/*Platinum*/
			time = show_timing();
			switch(time) {
				case 1:/*12:00pm*/					
				fp = fopen("p.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);			
				select_seats();
				break;	
				
			case 2:/*3:00pm*/
				fp = fopen("p.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
				
			case 3:/*6:00pm*/
				fp = fopen("p.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;

			case 4:/*9:00pm*/
				fp = fopen("p.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
			
			default:
				break;			
			}
			break;
		case 3:/*Gold*/
			time = show_timing();
			switch(time) {
				case 1:/*12:00pm*/					
				fp = fopen("g.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);			
				select_seats();
				break;	
				
			case 2:/*3:00pm*/
				fp = fopen("g.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
				
			case 3:/*6:00pm*/
				fp = fopen("g.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;

			case 4:/*9:00pm*/
				fp = fopen("g.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
			
			default:
				break;
			}
			break;
		case 4:/*Silver*/
			time = show_timing();
			switch(time) {
				case 1:/*12:00pm*/					
				fp = fopen("s.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);			
				select_seats();
				break;	
				
			case 2:/*3:00pm*/
				fp = fopen("s.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
				
			case 3:/*6:00pm*/
				fp = fopen("s.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;

			case 4:/*9:00pm*/
				fp = fopen("s.txt", "r");
				while((c = getc(fp)) != EOF) {
					printf("%c", c);
					fscanf(fp, "%s", str);
					Seat_Availability(&p, str);
				}
				fclose ( fp );
				Show_Seats(&p);
				select_seats();
				break;
			
			default:
				break;
			}
			break;
		default:
			break;

	}

	return 0;

}
