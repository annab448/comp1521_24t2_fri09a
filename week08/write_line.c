#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s file_name\n", argv[0]);
		exit(1);
	}

	char *path = argv[1];

	FILE *stream = fopen(path, "w");
	if (stream == NULL) {
		perror(path);
		exit(1);
	}

	int c;
	while ((c = fgetc(stdin)) != EOF) {
		fputc(c, stream);
		if (c == '\n') {
			break;
		}
	}
	
	fclose(stream);
}
