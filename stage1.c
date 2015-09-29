/*Movie Ticket Booking System*/

#include<stdio.h>
#include<string.h>

/*Structures to be used*/

typedef struct booking {
	char city[16];
	char cinema[16];
	char Movie[128];
	char Seat[16][16];
	float Ticket;
	int Availability;
}booking; 
booking Book[50];

/*Functions Prototypes*/

int printmenu();
void cinema_hall();
void movie();
void Showtimings();
void Empty();
void Seatbooked();
void Show();
void booking_ID();
void exit();	

int printmenu() {
	int choice;
	printf("1. Enter City Name\n"\
		"2. Enter Cinema Hall\n"\
		"3. Movie Name\n"\
		"4. Timing\n"\
		"5. Class\n"\
		"6. Seat\n"\
		"7. Ticket\n"\
		"8. Availability\n"\
		"9. exit \n");
	scanf("%d", &choice);	
	return choice;
}
int main() {
	int choice;
	choice = printmenu();
			switch(choice) {
			case 1: /*City Name*/ 
				break;
			case 2: /*Cinema Hall*/
				break;
			case 3: /*Movie Name*/
				break;
			case 4: /*Timing*/
				break;
			case 5: /*Class*/
				break;			
			case 6: /*Seat*/
				break;
			case 7: /*Ticket*/
				break;
			case 8: /*Availability*/
				break;
			case 9: /*exit */
				exit(0);
				break;
			}	
	return 0;
}
