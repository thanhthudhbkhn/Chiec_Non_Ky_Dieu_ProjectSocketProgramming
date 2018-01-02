/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "main.h"
#include "validate.h"
#include <stdlib.h>
#include <string.h>
#define PLAYING_GAME 0
#define QUIT_GAME 1
#define GAME_RUNNING 0
#define GAME_OVER 1
#define DELIMITER "####"

struct game current_game;

void addUser(client_message *argp) {
   FILE *fp = fopen("./database/user.db","a+");
   if(fp != NULL) {
       char data[517]  = "";
       strcpy(data,argp->current_user.name);
       strcat(data,DELIMITER);
       strcat(data,argp->current_user.pass);
       strcat(data,"\n");
       fputs(data,fp);
       fclose(fp);
   }
}

struct Quiz get_the_quiz() {
  struct Quiz quiz;
  char question[100];
  char answer[100];
  char temp[100];
  char *tokens;
  char line[100];
  FILE *fp = fopen("./database/quiz.db","r");
  if(fp!=NULL) {
    if (fgets(temp, 100, fp)!=NULL) {
      strcpy(line,temp);
      while (fgets(temp, 100, fp) != NULL) {
        if (rand()%2 == 0) strcpy(line,temp);
      }
    }
    fclose(fp);
  } else printf("open file error\n");
  tokens = strtok(line, DELIMITER);
  if (tokens != NULL) {
    strcpy(quiz.question, tokens);
  }
  tokens = strtok(NULL,DELIMITER);
  tokens[strlen(tokens)-1] = '\0';
  if (tokens != NULL) {
    strcpy(quiz.answer, tokens);
  }
  return quiz;
}

server_message *
register_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;
	if(!isRegisteredUsername(argp))
	{
		addUser(argp);
		result.opcode = 00;
	} else result.opcode = 01;
	return &result;
}

server_message *
login_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;
  if(isValidUser(argp)) {
    result.opcode = 10;
  } else result.opcode = 11;
  return &result;
}

server_message *
logout_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
join_1_svc(client_message *argp, struct svc_req *rqstp)
{
  static server_message result;
  result.opcode = 40;
  result.current_game.status = GAME_RUNNING;
  struct Quiz quiz = get_the_quiz();
  result.current_game.quiz = quiz;
  strcpy(result.current_game.answerAtMoment, "hoathi");
  result.current_game.joiners[0].user = argp->current_user;
  result.current_game.joiners[0].score = 0;
  result.current_game.joiners[0].in_game = PLAYING_GAME;
	return &result;
}

server_message *
spin_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;
	result.opcode = rand()%15;
	return &result;
}

server_message *
open_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
guess_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
guess_all_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
surender_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
function1_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
function2_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}

server_message *
function3_1_svc(client_message *argp, struct svc_req *rqstp)
{
	static server_message  result;

	/*
	 * insert server code here
	 */

	return &result;
}
