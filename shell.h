#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

char*** inputLine(char* prompt);
char** inputCommand(char* input);
int execute(char** command);
void prompt();
