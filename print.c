#include <stdio.h>

void print_spin_result(int spin_code){
	switch (spin_code) {
		case 0: printf("You got 100 scored!\n"); break;
		case 1: printf("You got 200 scored!\n"); break;
		case 2: printf("You got 300 scored!\n"); break;
		case 3: printf("You got 400 scored!\n"); break;
		case 4: printf("You got 500 scored!\n"); break;
		case 5: printf("You got 600 scored!\n"); break;
		case 6: printf("You got 700 scored!\n"); break;
		case 7: printf("You got 800 scored!\n"); break;
		case 8: printf("You got 900 scored!\n"); break;
		case 9: printf("You got 1000 scored!\n"); break;
		case 10: printf("You got the Gap doi\n"); break;
		case 11: printf("You got the Chia doi\n"); break;
		case 12: printf("You got the Mat luot\n"); break;
		case 13: printf("You got the Them luot\n"); break;
		case 14: printf("You got the May man\n"); break;
		default: break;
	}
}
