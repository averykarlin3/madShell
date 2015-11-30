#include "shell.h"
#include "parser.h"

int main(int argc, char **argv) {
	char *command1[10] = {argv[1]};
	char *command2[10] = {argv[2], argv[3]};
	pipingHot(command1, command2);
	return 0;
}
