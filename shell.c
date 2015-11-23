#include "shell.h"

char* prompt() {
	/** Returns a suitable prompt for use in the shell.
	 */
	char* home = getenv("HOME");
	char* cwd = get_current_dir_name(void);
	char* prompt = (char *)malloc(256);
	if(strstr(cwd, home)) {
		
	}
}

char*** inputLine(char* prompt) {
	/** Responsible for user interaction.
	 * 
	 * 	Returns:
	 * 		Input to be executed, divided up into commands and their options.
	 * 	
	 * 	Arguments:
	 * 		char* prompt: a suitable user prompt.
	 */
	char* s = (char *)malloc(sizeof(char) * 256);
	char*** scol = (char ***)malloc(sizeof(char **) * 256);	
	printf("$ ");
	fgets(s, sizeof(s), stdin);
	char* news;
	char* sp = s;
	printf("%s", sp);
	sp = strsep(&sp, "\n");
	int c = 0;
	while(sp) {
		news = strsep(&sp, ";");
		scol[c] = inputCommand(news);
		c++;
	}
	scol[c] = 0;
	return scol;
}

char** inputCommand(char* input) {
	char** sar = (char **)malloc(sizeof(char *) * 256);
	char* news;
	int c = 0;
	while(input) {
		news = strsep(&input, " ");
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

