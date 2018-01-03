#include <stdio.h>
#include <string.h>
#include "main.h"

void print_spin_result(int spin_code){
	switch (spin_code) {
		case 100_SCORES: printf("You got 100 scored!\n"); break;
		case 200_SCORES: printf("You got 200 scored!\n"); break;
		case 300_SCORES: printf("You got 300 scored!\n"); break;
		case 400_SCORES: printf("You got 400 scored!\n"); break;
		case 500_SCORES: printf("You got 500 scored!\n"); break;
		case 600_SCORES: printf("You got 600 scored!\n"); break;
		case 700_SCORES: printf("You got 700 scored!\n"); break;
		case 800_SCORES: printf("You got 800 scored!\n"); break;
		case 900_SCORES: printf("You got 900 scored!\n"); break;
		case 1000_SCORES: printf("You got 1000 scored!\n"); break;
		case THE_DOUBLE: printf("You got the Double. Your score will be x2.\n"); break;
		case THE_DIVIDE: printf("You got the Divide by 2. Your score will be :2 :( \n"); break;
		case LOST_A_TURN: printf("You got the Mat luot\n"); break;
		case GAIN_A_TURN: printf("You got the Them luot\n"); break;
		case LUCKY: printf("You got the May man\n"); break;
		default: break;
	}
}

void print_project_info() {
	printf("Network Programming Project - Jan 2018\nWHEEL OF FORTUNE\n");
	printf("Phan Thanh Thu - 20144424\nPhung Van Khanh - 20142319\n");
	printf("----------------------------------------------------------------------\n" );
}

void print_welcome(){
	printf("----------------------------------------------------------------------\n" );
	printf("WELCOME TO THE GAME.\n");
}

void menu_login() {
	printf("----------------------------------------------------------------------\n" );
	printf("1.Register\n2.Login\nEnter exactly your choice: ");
}
void print_logout() {
	printf("Good bye.\n\n\n\n");
}
void menu_joingame() {
	printf("----------------------------------------------------------------------\n" );
	printf("1.Join game\n2.Logout\nEnter exactly your choice: ");
}

void menu_spin() {
	printf("----------------------------------------------------------------------\n" );
	printf("1.Spin\n2.Guess all the quiz\n3.Quit the game\nEnter exactly your choice: ");
}
void print_quiz(server_message *message){
	printf("----------------------------------------------------------------------\n" );
	printf("Today quiz:\n    %s\n",message->current_game.quiz.question );
	char *answer = message->current_game.quiz.answer;
	int length = (int)strlen(answer);
	printf("The answer has %d character(s):\n    ", length);
	for(int i=0;i<length;i++) {
		if(answer[i]!=' ') printf("*");
		else printf(" ");
	}
	printf("\n");
}
