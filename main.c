#include "shell.h"

int main() {
	int done = 0;
	char* command;
	char** curCommand;
	while(!done) {
		command = inputLine();
		int i = 0;
		while(command && !done) {
			curCommand = inputCommand(strsep(&command, ";"));
			if(!strcmp(curCommand[0], "exit")) {
				done++;
			}
			else if(!strcmp(curCommand[0], "cd")) {
				chdir(curCommand[1]);
			}
			else {
				int fail = execute(curCommand);
			}
			i++;
		}
	}
	return 0;
}
