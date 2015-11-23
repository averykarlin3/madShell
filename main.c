#include "shell.h"

int main() {
	int done = 0;
	char*** command;
	char* path = (char *)malloc(sizeof(char) * 256);
	while(!done) {
		command = inputLine();
		int i = 0;
		while(command[i] && !done) {
			if(!strcmp(command[i][0], "exit")) {
				done++;
			}
			else if(!strcmp(command[i][0], "cd")) {
				path = chdir(path, command[i][1]);
			}
			else {
				printf("%s", command[i][1]); //Cuts off after 4 characters for some reason - Bug
				printf("%s", command[i][2]);
				int fail = execute(path, command[i]);
				if(fail)
					printf("%s\n", strerror(fail));
			}
			i++;
		}
	}
	return 0;
}
