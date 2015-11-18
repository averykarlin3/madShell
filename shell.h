#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

char*** inputLine();
char** inputCommand(char* input);
int execute(char** command);
