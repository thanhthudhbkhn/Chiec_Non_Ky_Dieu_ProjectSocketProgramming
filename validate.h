#ifndef VALIDATE_H
#define VALIDATE_H
#include <stdbool.h>

char validate_choice(char *choice, char bot, char top);
bool isRegisteredUsername(client_message *argp);
bool isValidUser(client_message *argp);
#endif
