#ifndef VALIDATE_H
#define VALIDATE_H
#include <stdbool.h>

int validate_choice(int *choice, int bot, int top);
bool isRegisteredUsername(client_message *argp);
bool isValidUser(client_message *argp);
#endif
