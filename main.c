#include "shell.h"

int main() {
	int done = 0;
	char** command;
	while(!done) {
		command = input();
		if(!strcmp(command[0],"exit")) {
			done++;
		}
		else {
		//Other Stuff
		}
	}
	return 0;
}
