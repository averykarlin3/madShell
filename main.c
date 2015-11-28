#include "shell.h"

int main() {
	int done = 0;
	char* command;
	char* sepCommand; // a piece of command before a ;
	char** curCommand; // a command in a format to be executed
	while(!done) {
		command = inputLine();
		int i = 0;
		while(command && !done) {
			sepCommand = strsep(&command, ";");
			curCommand = inputCommand(sepCommand);
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