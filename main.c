#include "shell.h"

int main() {
	int done = 0;
	char* command;
	char** curCommand;
	while(!done) {
		command = inputLine();
		//printf("%s\n",command);
		curCommand = inputCommand(command);
		int i = 0;
		while(command && !done && curCommand) {
			//printf("%s\n", command);
			//printf("%s\n", command);
			//strsep(&command, ";");
			//printf("%s\n", command);
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
			//curCommand = inputCommand(command);
			command = NULL;
		}
	}
	return 0;
}
