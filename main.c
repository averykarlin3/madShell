#include "shell.h"

int main() {
	int done = 0;
	char*** command;
	while(!done) {
		command = inputLine();
		int i = 0;
		while(command[i] != 0 && !done) {
			if(!strcmp(command[i][0],"exit")) {
				done++;
			}
			else if(!strcmp(command[i][0], "cd")) {
			//cd
			}
			else {
			//Other Stuff
			}
			i++;
		}
	return 0;
	}
}
