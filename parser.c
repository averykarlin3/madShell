#include "parser.h"
#include "shell.h"

char* inputLine() {
	/** Function: Gives the shell prompt and reads in the text the user enters.
	 * 
	 * 	Returns:
	 * 		The text entered into stdin with the newline char removed
	 */
	char sin[256];
	char* s = (char *)malloc(sizeof(char) * 256);;
	prompt();
	fgets(sin, sizeof(sin), stdin);
	strcpy(s, sin);
	char* sp = s;
	sp = strsep(&sp, "\n");
	return sp;
}

char** inputCommand(char* input) {
	/* Input: Takes in the line containing one full command (e.g. "ls -l")

	   Returns: An array of strings with each element in the array containing a different section of the command 
	   (e.g. ["ls", "-l"])
	*/
	char* inputc = (char *)malloc(sizeof(char) * 256); //copy of input so we don't have to modify input
	strcpy(inputc, input);
	char** sar = (char **)malloc(sizeof(char *) * 256);
	char* news;
	int c = 0;
	//remove spaces from end of input
	while (inputc[strlen(inputc) - 1] == ' ') {
		inputc[strlen(inputc) - 1] = '\0';
	}
	while(inputc) {
		news = strsep(&inputc, " ");
		//make sure news isn't empty
		while (!strcmp(news, "\0") && inputc) {
			news = strsep(&inputc, " ");
		}
		//get rid of any extra spaces at the beginning of input
		if (inputc) {
			while (inputc[0] == ' ') {
				strsep(&inputc, " ");
			}
		}
		sar[c] = news;
		c++;
	}
	sar[c] = 0;
	return sar;
}
