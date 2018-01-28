#include <stdio.h>
#include <string.h>
#include "main.h"

void print_spin_result(int spin_code){
	switch (spin_code) {
		case 0: printf("You will earn 100 scores for each correct character!\n"); break;
		case 1: printf("You will earn 200 scores for each correct character!\n"); break;
		case 2: printf("You will earn 300 scores for each correct character!\n"); break;
		case 3: printf("You will earn 400 scores for each correct character!\n"); break;
		case 4: printf("You will earn 500 scores for each correct character!\n"); break;
		case 5: printf("You will earn 600 scores for each correct character!\n"); break;
		case 6: printf("You will earn 700 scores for each correct character!\n"); break;
		case 7: printf("You will earn 800 scores for each correct character!\n"); break;
		case 8: printf("You will earn 900 scores for each correct character!\n"); break;
		case 9: printf("You will earn 1000 scores for each correct character!\n"); break;
		case THE_DOUBLE: printf("You got the Double. Your current score will be x2 for each correct character.\n"); break;
		case THE_DIVIDE: printf("You got the Divide by 2. Your score will be :2 if your guess is incorrect.\n"); break;
		// case LOST_A_TURN: printf("You got the Mat luot\n"); break;
		// case GAIN_A_TURN: printf("You got the Them luot\n"); break;
		// case LUCKY: printf("You got Lucky. You can choose to open a position of the answer.\n"); break;
		default: break;
	}
}

void print_project_info() {
	printf("Network Programming Project - Jan 2018\nWHEEL OF FORTUNE\n");
	printf("Phan Thanh Thu - 20144424\n");
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
