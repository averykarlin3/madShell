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
				chdir(command[i][1]);
			}
			else {
				int fail = execute(command[i]);
			}
			i++;
		}
	}
	return 0;
}
