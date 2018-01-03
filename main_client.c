/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "print.h"
#include "validate.h"

struct Session{
    struct User user;
    int sessStatus;// AUTHENTICATED, NOT AUTHENTICATED…
    struct sockaddr_in cliaddr;
};

int guess(int opcode, CLIENT *clnt) {
	client_message  guess_1_arg;
	server_message  *result_7;
  char character;
  char tmp[4];

  printf("(Please enter only a character from 'a' to 'z') I guess: ");
  scanf("%c%*c",&character);

  strcpy(guess_1_arg.command,"GUESS");
  sprintf(tmp, "%d", opcode);
  strcpy(guess_1_arg.parameter,tmp);
  strcat(guess_1_arg.parameter,"####");
  tmp[0] = character;tmp[1]='\0';
  strcat(guess_1_arg.parameter,tmp);
  result_7 = guess_1(&guess_1_arg, clnt);
	if (result_7 == (server_message *) NULL) {
		clnt_perror (clnt, "call failed");
	} else {
    if (result_7->opcode == CORRECT) printf("Good job! The answer contains '%c'.\n", character );
    else if (result_7->opcode == INCORRECT) printf("Oops! The answer does not contain '%c'.\n", character );
    else if (result_7->opcode == COMPLETED) {
      printf("Congratulation! You have completed the quiz!\n");
      sleep(2);
    }

    printf("\nToday quiz:\n    %s\n",result_7->current_game.quiz.question );
  	int length = (int)strlen(result_7->current_game.quiz.answer);
  	printf("The answer has %d character(s):\n    ", length);
    printf("    %s\n",result_7->current_game.answerAtMoment );
    printf("Your score: %d!\n",result_7->current_game.joiners[0].score );
  }
  return result_7->current_game.status;
}

void play_game(CLIENT *clnt) {
	server_message  *result_5;
	client_message  spin_1_arg;
	server_message  *result_8;
	client_message  guess_all_1_arg;
  int game_status = GAME_RUNNING;
  char full_answer[100];
  char choice;
  do {
    menu_spin();
    /*spin, guess all or quit game*/
    scanf("%c%*c",&choice);
    choice = validate_choice(&choice,'1','3');
    switch (choice) {
      case '1':
        strcpy(spin_1_arg.command,"SPIN");
        result_5 = spin_1(&spin_1_arg, clnt);
        if (result_5 == (server_message *) NULL) {
          clnt_perror (clnt, "call failed");
        } else {
          // sleep(1);
          system("clear");
          print_spin_result(result_5->opcode);
          switch (result_5->opcode) {
            case 0: game_status = guess(0,clnt); break;
        		case 1: game_status = guess(1,clnt); break;
        		case 2: game_status = guess(2,clnt); break;
        		case 3: game_status = guess(3,clnt); break;
        		case 4: game_status = guess(4,clnt); break;
        		case 5: game_status = guess(5,clnt); break;
        		case 6: game_status = guess(6,clnt); break;
        		case 7: game_status = guess(7,clnt); break;
        		case 8: game_status = guess(8,clnt); break;
        		case 9: game_status = guess(9,clnt); break;
        		case THE_DOUBLE: game_status = guess(THE_DOUBLE,clnt); break;
        		case THE_DIVIDE: game_status = guess(THE_DIVIDE,clnt); break;
        		// case LOST_A_TURN: game_status = guess(LOST_A_TURN,clnt); break;
        		// case GAIN_A_TURN: game_status = guess(GAIN_A_TURN,clnt); break;
        		case LUCKY: game_status = guess(LUCKY,clnt); break;
        		default: break;
          }
        }
        break;
      case '2':
        printf("Enter the full answer: ");
        fgets(full_answer, 100, stdin);
        int c;
        // while ((c=getchar()) != '\n' && c != EOF);
        full_answer[strlen(full_answer)-1]='\0';

        if (full_answer != NULL) {
          strcpy(guess_all_1_arg.parameter,full_answer);
          result_8 = guess_all_1(&guess_all_1_arg, clnt);
          if (result_8 == (server_message *) NULL) {
            clnt_perror (clnt, "call failed");
          } else {
            if (result_8->opcode == COMPLETED){
              printf("Congratulation! You have completed the quiz!\n");
              sleep(2);
            } else {
              printf("Your answer is wrong. See you again!\n" );
            }
            game_status = GAME_OVER;
          }
        }
        break;
      case '3': break;
      default: break;
    }
  } while (choice!='3' && game_status == GAME_RUNNING);
}

void
wheel_prog_1(char *host)
{
	CLIENT *clnt;
	server_message  *result_1;
	client_message  register_1_arg;
	server_message  *result_2;
	client_message  login_1_arg;
	server_message  *result_3;
	client_message  logout_1_arg;
	server_message  *result_4;
	client_message  join_1_arg;
	server_message  *result_5;
	client_message  spin_1_arg;
	server_message  *result_6;
	client_message  open_1_arg;
	server_message  *result_7;
	client_message  guess_1_arg;
	server_message  *result_8;
	client_message  guess_all_1_arg;
	server_message  *result_9;
	client_message  surender_1_arg;
  char choice;
  struct Session session;
  struct game current_game;

#ifndef	DEBUG
	clnt = clnt_create (host, WHEEL_PROG, V1, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

  print_project_info();
  menu_login();
  /* register or login*/
  scanf("%c%*c",&choice);
  choice = validate_choice(&choice,'1','2');
  switch (choice) {
    case '1':
      strcpy(register_1_arg.command,"REGISTER");
      do {
        printf("Enter the username (without space): ");
  		  scanf("%s%*c", register_1_arg.current_user.name);
  		  printf("Enter the password (without space): ");
  		  scanf("%s%*c", register_1_arg.current_user.pass);

        result_1 = register_1(&register_1_arg, clnt);

        if (result_1 == (server_message *) NULL) {
          clnt_perror (clnt, "call failed"); break;
        }
        if (result_1->opcode == 0) {
          printf("Register successful!\n");
          session.user = register_1_arg.current_user;
          session.sessStatus = AUTHENTICATED;
        }
        else if (result_1->opcode == 1){
          printf("Your username is existed. Please register with another name.\n");
          session.sessStatus = NOT_AUTHENTICATED;
        }
      } while (result_1->opcode == 1);
      break;
    case '2':
      strcpy(login_1_arg.command,"LOGIN");
      do {
        printf("Enter the username: ");
        scanf("%s%*c", login_1_arg.current_user.name);
        printf("Enter the password: ");
        scanf("%s%*c", login_1_arg.current_user.pass);

        result_2 = login_1(&login_1_arg, clnt);

        if (result_2 == (server_message *) NULL) {
          clnt_perror (clnt, "call failed"); break;
        }
        if (result_2->opcode == 10) {
            printf("Login successful!\n");
            session.user = login_1_arg.current_user;
            session.sessStatus = AUTHENTICATED;
        }
        else if (result_2->opcode == 11){
          printf("Your username and password not match.\n");
        }
      } while (result_2->opcode == 11);
      break;
    default: break;
  }

  if (session.sessStatus == AUTHENTICATED) {
    menu_joingame();
    /*join game or logout*/
    scanf("%c%*c",&choice);
    choice = validate_choice(&choice,'1','2');
    switch (choice) {
      case '1'://join
        print_welcome();
        strcpy(join_1_arg.command,"JOIN");
        result_4 = join_1(&join_1_arg, clnt);
        if (result_4 == (server_message *) NULL) {
          clnt_perror (clnt, "call failed");
        } else {
          print_quiz(result_4);
          current_game = result_4->current_game;
          play_game(clnt);
        }
        break;
      case '2'://logout
        session.sessStatus = NOT_AUTHENTICATED;
        strcpy(session.user.name, "");
        strcpy(session.user.pass, "");
        print_logout();
        wheel_prog_1 (host);
        break;
      default: break;
    }
  }

	result_3 = logout_1(&logout_1_arg, clnt);
	if (result_3 == (server_message *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	result_6 = open_1(&open_1_arg, clnt);
	if (result_6 == (server_message *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	result_9 = surender_1(&surender_1_arg, clnt);
	if (result_9 == (server_message *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	wheel_prog_1 (host);
exit (0);
}
