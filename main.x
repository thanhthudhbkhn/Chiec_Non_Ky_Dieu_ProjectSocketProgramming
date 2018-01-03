const NOT_AUTHENTICATED = 0;
const AUTHENTICATED = 1;
const PLAYING_GAME = 0;
const QUIT_GAME = 1;
const GAME_RUNNING = 0;
const GAME_OVER = 1;
const THE_DOUBLE = 10;
const THE_DIVIDE = 11;
const LOST_A_TURN = 12;
const GAIN_A_TURN = 13;
const LUCKY = 14;
const CORRECT = 70;
const INCORRECT = 71;
const COMPLETED = 72;
const DELIMITER = "####";

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

struct Joiner{
    struct User user;
    int score;
    int in_game;
};

struct Quiz{
  char question[100];
  char answer[100];
};

struct game{
    int status; /*0: game kết thúc, 1: còn game*/
    struct Joiner joiners[3];
    struct Quiz quiz;
    char answerAtMoment[100];
};

struct server_message {
	int opcode;
  game current_game;
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
