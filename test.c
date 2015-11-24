#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void prompt();

int main() {
    prompt();
    return 0;
}

void prompt() {
	/* Prints a suitable prompt for use in the shell.
	 * 	*/
	char* home = getenv("HOME");
	char* cwd = getenv("PWD");
	char* hostname = (char *)malloc(256);
	gethostname(hostname, 256);
	char* username = getenv("USER");
	printf("%s@%s:", username, hostname);
	if(strstr(cwd, home)) {
		printf("~%s", cwd+strlen(home));
	}
	else {
		printf("%s", cwd);
	}
	printf("$ ");
	fflush(stdout);
}													
