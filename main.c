#include "shell.h"
#include "parser.h"

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
			int fail = execute(curCommand);
			i++;
		}
	}
	return 0;
}