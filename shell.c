#include "shell.h"

char*** inputLine() {
	char* s = (char *)malloc(sizeof(char) * 256);
	char*** scol = (char ***)malloc(sizeof(char **) * 256);	
	printf("$ ");
	fgets(s, sizeof(s), stdin);
	char* news;
	char* sp = s;
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
	char* s = (char *)malloc(sizeof(char) * 256);
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
	int chP = fork();
	int status;
	if(!chP) {
		int c = execvp(command[0], command);
		exit(c);
	}
	else {
		waitpid(chP, &status);
	}
	return status;
}
