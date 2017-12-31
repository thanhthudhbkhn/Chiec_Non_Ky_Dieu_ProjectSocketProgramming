#include <stdio.h>

int validate_choice(int *choice, int bot, int top){
	if ((*choice < bot)||(*choice > top)) {
		printf("Your choice is not valid. Enter your choice again:\n");
		scanf("%d",choice);
	}
	return *choice;
}
