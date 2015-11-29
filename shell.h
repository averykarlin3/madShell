#ifndef IMPORTS
#define IMPORTS 1

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#endif

#ifndef SHELL_H
#define SHELL_H 1

int execute(char** command);
void prompt();
int redirectIn(char* fileName);
int redirectOut(char* fileName);

#endif