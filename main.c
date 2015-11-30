#include "shell.h"
#include "parser.h"

int main() {
	char* command;
	char* sepCommand; // a piece of command before a ;
	char** curCommand; // a command in a format to be executed
	char* mainCommand[256]; // command to be run
	char* stdinFil = NULL;  //file redirected in
	char* stdoutFil = NULL; //file redirected out
	char* pipe2 = NULL;
	char* tempString;
	int stdinCop;
	int stdoutCop;
	while (1) {
		command = inputLine();
		while(command) {
			sepCommand = strsep(&command, ";");
			if (findIndex(sepCommand, "<") != 257 || findIndex(sepCommand, ">") != 257) {
				if (findIndex(sepCommand, "<") == 257) {
					tempString = strsep(&sepCommand, ">");
					stdoutFil = sepCommand;
					sepCommand = tempString;
				}
				else if (findIndex(sepCommand, ">") == 257) {
					tempString = strsep(&sepCommand, "<");
					stdinFil = sepCommand;
					sepCommand = tempString;
				}
				else {
					if (findIndex(sepCommand, ">") < findIndex(sepCommand, "<")) {
						tempString = strsep(&sepCommand, ">");
						stdoutFil = strsep(&sepCommand, "<");
						stdinFil = sepCommand;
						sepCommand = tempString;
					} 
					else {
						tempString = strsep(&sepCommand, ">");
						stdinFil = strsep(&sepCommand, "<");
						stdoutFil = sepCommand;
						sepCommand = tempString;
					}
				}
			}
			else if(findIndex(sepCommand, "|") != 257) { 
				tempString = strsep(&sepCommand, "|");
				pipe2 = sepCommand;
				sepCommand = tempString;
			}
			
			if (stdinFil) {
				stdinCop = redirectIn(removeWhiteSpace(stdinFil));
			}
			if (stdoutFil) {
				stdoutCop = redirectOut(removeWhiteSpace(stdoutFil));
			}
			if(pipe2) {
				pipingHot(inputCommand(removeWhiteSpace(sepCommand)), inputCommand(removeWhiteSpace(pipe2)));
			}
			else {
				curCommand = inputCommand(sepCommand);
				int fail = execute(curCommand);
			}
			if (stdinFil) {
				dup2(stdinCop, 0);
			}
			if (stdoutFil) {
				dup2(stdoutCop, 1);
			}
		}
	}
	return 0;
}
