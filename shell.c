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
	/** Responsible for user interaction.
	 * 
	 * 	Returns:
	 * 		Input to be executed, divided up into commands and their options.
	 */
	char sin[256];
	char* s = (char *)malloc(sizeof(char) * 256);;
	//char** scol = (char **)malloc(sizeof(char *) * 256);
	prompt();
	fgets(sin, sizeof(sin), stdin);
	strcpy(s, sin);
	char* news;
	char* sp = s;
	sp = strsep(&sp, "\n");
	return sp;
}

char** inputCommand(char* input) {
	char** sar = (char **)malloc(sizeof(char *) * 256);
	char* news;
	int c = 0;
	while(input) {
		news = strsep(&input, " ");
		while (!strcmp(news, "\0")) {
			news = strsep(&input, " ");
		}
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

