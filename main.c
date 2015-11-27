#include "shell.h"

int main() {
	int done = 0;
	char*** command;
	while(!done) {
		command = inputLine();
		printf("%s\n", command[0][0]);
		printf("%s\n", command[0][1]);
		int i = 0;
		while(command[i] && !done) {
			if(!strcmp(command[i][0], "exit")) {
				done++;
			}
			else if(!strcmp(command[i][0], "cd")) {
				chdir(command[i][1]);
			}
			else {
				//printf("%s\n", command[i][0]);
				//printf("%s\n", command[i][1]); //Cuts off after 4 characters for some reason - Bug
				//printf("%s\n", command[i][2]);
				//printf("done\n");
				int fail = execute(command[i]);
				//if(fail)
				//	printf("%s\n", strerror(fail));
			}
			i++;
		}
	}
	return 0;
}
