#include "main.h"
#include <stdio.h>
#include <stdbool.h>

int validate_choice(int *choice, int bot, int top){
	if ((*choice < bot)||(*choice > top)) {
		printf("Your choice is not valid. Enter exactly your choice again:\n");
		scanf("%d",choice);
	}
	return *choice;
}

bool isRegisteredUsername(client_message *argp) {
    FILE *fp;
    char* delimiter = "####";
    char* tokens;
    char temp[517];
    int read;
    fp = fopen("./user.db","r");
    if(fp == NULL){
	return FALSE;
    }
    while(fgets(temp, 517, fp) != NULL) {
	tokens = strtok(temp, delimiter );
	if (tokens != NULL)
	{
		if((strcmp(tokens, argp->current_user.name)) == 0) {
		    fclose(fp);
		    return TRUE;
		}
	}
    }
    fclose(fp);
    return FALSE;
}

bool isValidUser(client_message *argp) {
    FILE *fp;
    char* delimiter = "####";
    char* tokens;
    char temp[517];
    char input[517];
    fp = fopen("./user.db","r");
    if(fp == NULL){
	return FALSE;
    }

    strcpy(input,argp->current_user.name);
    strcat(input,delimiter);
    strcat(input,argp->current_user.pass);
    strcat(input,"\n");
    while(fgets(temp, 517, fp) != NULL) {
	if((strcmp(temp, input)) == 0) {
	    fclose(fp);
	    return TRUE;
	}
    }
    fclose(fp);
    return FALSE;
}
