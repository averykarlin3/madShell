#include "shell.h"

void prompt() {
	/* Prints a prompt for the shell.
	 */
	char *home = getenv("HOME");
	char *cwd = (char *)malloc(256);
	getcwd(cwd,256);
	char *hostname = (char *)malloc(256);
	gethostname(hostname, 256);
	char *username = getenv("USER");
	printf("\e[31;1m\e[40;1m(MAD)\e[0m");
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

int execute(char** command) {
	/*	Input:  An array of strings with each element in the array containing a different section of the command
		
		Function: Executes the entered command

		Returns: WEXITSTATUSis 
	*/
	if (!strcmp(command[0],"")) {
		return 1;
	}
	else if(!strcmp(command[0], "exit")) {
		exit(0);
	}
	else if(!strcmp(command[0], "cd")) {
		return chdir(command[1]);
	}
	else {
		pid_t chP = fork();
		int status = 0;
		if(chP == 0) {
			int c = execvp(command[0], command);
			exit(errno);
		}
		else {
			wait(&status);
		}
		return WEXITSTATUS(status);
	}
}

int redirectIn(char* fileName) {
	/* Input: fileName -  The file path of the desired input file 
	Creates the file table entry for fileName, then sets stdin to it after copying the entry for stdin
	Output: stdinCop - The file descriptor of the copied stdin
	*/
	int desc = open(fileName, O_RDONLY, 0744);
	int stdinCop = dup(0);
	dup2(desc, 0);
	close(desc);
	return stdinCop;
}

int redirectOut(char* fileName) {
	/* Input: fileName -  The file path of the desired output file 
	Creates the file table entry for fileName, then sets stdout to it after copying the entry for stdout
	Output: stdoutCop - The file descriptor of the copied stdout
	*/
	int desc = open(fileName, O_WRONLY | O_TRUNC | O_CREAT, 0744);
	int stdoutCop = dup(1);
	dup2(desc, 1);
	close(desc);
	return stdoutCop;
}

void pipingHot(char **command1, char **command2) {
	/**	Pipes two commands.
	 * 	
	 *	Parameters:
	 *		command1: the one on the left.
	 *		command2: the one on the right. No, the other right.
	 */
	int fd[2];
	int stdinA = dup(0);
	int stdoutA = dup(1);
	pid_t childpid;
	pipe(fd);
	if(!fork()) {
		dup2(fd[1], 1);
		close(fd[0]);
		execute(command1);
	}
	else {
		dup2(fd[0], 0);
		close(fd[1]); // close read side of pipe
		execute(command2);
		//exit(0);
	}
	dup2(stdinA, 0);
	dup2(stdoutA, 1);
}
