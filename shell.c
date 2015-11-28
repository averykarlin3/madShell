#include "shell.h"

void prompt() {
	/* Prints a suitable prompt for use in the shell.
	 * 	*/
	char *home = getenv("HOME");
	char *cwd = (char *)malloc(256);
	getcwd(cwd,256);
	char *hostname = (char *)malloc(256);
	gethostname(hostname, 256);
	char *username = getenv("USER");
	printf("\e[31;1m\e[40;1m(MAD)\e[0m");
	printf("%s@%s:", username, hostname);
	if(strstr(cwd, home)) {
		printf("~%s", cwd+strlen(home));
	}
	else {
		printf("%s", cwd);
	}
	printf("$ ");
	fflush(stdout);
}

char* inputLine() {
	/** Function: Gives the shell prompt and reads in the text the user enters.
	 * 
	 * 	Returns:
	 * 		The text entered into stdin with the newline char removed
	 */
	char sin[256];
	char* s = (char *)malloc(sizeof(char) * 256);;
	prompt();
	fgets(sin, sizeof(sin), stdin);
	strcpy(s, sin);
	char* sp = s;
	sp = strsep(&sp, "\n");
	return sp;
}

char** inputCommand(char* input) {
	/* Input: Takes in the line containing one full command (e.g. "ls -l")

	   Returns: An array of strings with each element in the array containing a different section of the command 
	   (e.g. ["ls", "-l"])
	*/
	char** sar = (char **)malloc(sizeof(char *) * 256);
	char* news;
	int c = 0;
	//remove spaces from end of input
	while (input[strlen(input) - 1] == ' ') {
		input[strlen(input) - 1] = '\0';
	}
	while(input) {
		news = strsep(&input, " ");
		//make sure news isn't empty
		while (!strcmp(news, "\0")) {
			news = strsep(&input, " ");
		}
		//get rid of any extra spaces at the beginning of input
		if (input) {
			while (input[0] == ' ') {
				strsep(&input, " ");
			}
		}
		sar[c] = news;
		c++;
	}
	sar[c] = 0;
	return sar;
}

int execute(char** command) {
	/* 	Input:  An array of strings with each element in the array containing a different section of the command
		
		Function: Executes the entered command

		Returns: WEXITSTATUSis 
	*/
	if(!strcmp(command[0], "exit")) {
		exit(0);
	}
	else if(!strcmp(command[0], "cd")) {
		return chdir(command[1]);
	}
	else {
		pid_t chP = fork();
		int status = 0;
		if(chP == 0) {
			int c = execvp(command[0], command);
			exit(errno);
		}
		else {
			wait(&status);
		}
		return WEXITSTATUS(status);
	}
}

