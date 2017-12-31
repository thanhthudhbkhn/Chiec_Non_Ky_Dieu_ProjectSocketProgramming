struct User{
    char name[30];
    char pass[30];
		/* 0: blocked, 1: active, 2: playing */
		int accStatus;
};

struct client_message {
	char command[100];
  char parameter[100];
	User current_user;
};

struct server_message {
	int opcode;
};

program WHEEL_PROG {
  version V1 {
    server_message REGISTER(client_message) = 1;
    server_message LOGIN(client_message) 		= 2;
		server_message LOGOUT(client_message) 	= 3;
		server_message JOIN(client_message)			= 4;
		server_message SPIN(client_message)			= 5;
		server_message OPEN(client_message)			= 6;
		server_message GUESS(client_message)		= 7;
		server_message GUESS_ALL(client_message)= 8;
		server_message SURENDER(client_message)	= 9;
		server_message FUNCTION1(client_message)= 10;
		server_message FUNCTION2(client_message)= 11;
		server_message FUNCTION3(client_message)= 12;
  } = 1;
} = 0x33451111;
