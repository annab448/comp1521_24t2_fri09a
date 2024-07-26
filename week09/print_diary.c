#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	char *diary_path = ".diary";
	char *home_path = getenv("HOME");
	if (home_path == NULL) {
		home_path = ".";
	}

	int pathlen = strlen(diary_path) + strlen(home_path) + 2;
	char path[pathlen];

	snprintf(path, pathlen, "%s/%s", home_path, diary_path);

	FILE *stream = fopen(path, "r");
	if (stream == NULL) {
		perror(path);
		return 1;
	}

	int c;
	while ((c = fgetc(stream)) != EOF) {
		fputc(c, stdout);
	}

	fclose(stream);
}
