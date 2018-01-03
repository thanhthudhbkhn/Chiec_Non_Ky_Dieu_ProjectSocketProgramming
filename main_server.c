/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "main.h"
#include "validate.h"
#include <stdlib.h>
#include <string.h>

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

char * setdefaultAnswer(char* answer) {
  int i;
  char *defaultAnswer = answer;
  for (i=0;i<strlen(answer);i++) {
    if (defaultAnswer[i]!=' ') {
      defaultAnswer[i] = '*';
    }
  }
  return defaultAnswer;
}

char lower_to_upper(char lower) {
  char upper;
  if (lower >= 'a' && lower <= 'z') {
    upper = ('A' + lower - 'a');
    return upper;
  }
  else return lower;
}

int get_score(int spin_code, int score){
  switch (spin_code) {
    case 100_SCORES:
		case 200_SCORES:
		case 300_SCORES:
		case 400_SCORES:
		case 500_SCORES:
		case 600_SCORES:
		case 700_SCORES:
		case 800_SCORES:
		case 900_SCORES:
		case 1000_SCORES:
      score+=(spin_code+1)*100;
      return score;
		case THE_DOUBLE: return score*=2;
		case THE_DIVIDE: return score/=2;
		case LOST_A_TURN: printf("You got the Mat luot\n"); break;
		case GAIN_A_TURN: printf("You got the Them luot\n"); break;
		case LUCKY: printf("You got the May man\n"); break;
		default: break;
	}
  return current_game.joiners[0].score;
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
  strcpy(result.current_game.answerAtMoment, setdefaultAnswer(quiz.answer));
  result.current_game.joiners[0].user = argp->current_user;
  result.current_game.joiners[0].score = 0;
  result.current_game.joiners[0].in_game = PLAYING_GAME;
  current_game = result.current_game;
	return &result;
}

server_message *
spin_1_svc(client_message *argp, struct svc_req *rqstp)
{
  static server_message result;
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
  int i=0;
  current_game.status = GAME_OVER;
  int spin_code;
  char *character;
  char *answer = current_game.quiz.answer;
  // printf("%s\n",argp->parameter );
  // printf("%s\n",current_game.quiz.answer );
  // printf("%s\n",current_game.answerAtMoment );

  spin_code = atoi(strtok(argp->parameter, DELIMITER));
  character = strtok(NULL,DELIMITER);
  *character = lower_to_upper(*character);
  result.opcode = 71;
  for(i=0;i<strlen(current_game.answerAtMoment);i++) {
    if (current_game.answerAtMoment[i]=='*'){
      if (answer[i] == character[0]) {
        current_game.answerAtMoment[i] = character[0];
        result.opcode = 70;
        current_game.joiners[0].score = get_score(spin_code, current_game.joiners[0].score);
      }
    }
  }
  //check if the answer is completed?
  for(i=0;i<strlen(current_game.answerAtMoment);i++) {
    if (current_game.answerAtMoment[i]=='*'){
      current_game.status = GAME_RUNNING;
    }
  }
  if (current_game.status == GAME_OVER) result.opcode = 72;
  result.current_game = current_game;
  // printf("answerAtMoment:%s.\n",result.current_game.answerAtMoment );
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
