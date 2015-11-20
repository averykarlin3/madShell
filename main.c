#include "shell.h"

int main() {
	int done = 0;
	char*** command;
	while(!done) {
		command = inputLine();
		int i = 0;
		while(command[i] && !done) {
			if(!strcmp(command[i][0], "exit")) {
				done++;
			}
			else if(!strcmp(command[i][0], "cd")) {
			//cd
			}
			else {
				printf("%s", command[i][1]);
				printf("%s", command[i][2]);
				int fail = execute(command[i]);
				if(fail)
					printf("%s\n", strerror(fail));
			}
			i++;
		}
	}
	return 0;
}
