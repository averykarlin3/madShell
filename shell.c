#include "shell.h"

char** input() {
	char s[256];
	char* sar[256];
	printf("$");
	fgets(s, sizeof(s), stdin);
	char* news;
	char* sp = s;
	sp = strsep(&sp, "\n");
	int c = 0;
	while(sp) {
		news = strsep(&sp, " ");
		sar[c] = news;
		c++;
	}
	return sar;
}


