#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_MAX 2048

void search_stream(FILE *stream, char *search_string, char *file) {
	char line[LINE_MAX];	
	int line_no = 1;
	while (fgets(line, LINE_MAX, stream) != NULL) {
		if (strstr(line, search_string) != NULL) {
			printf("%s:%d:%s", file, line_no, line);
		}
		line_no++;
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s search_string <filenames>\n", argv[0]);
		exit(1);
	}

	if (argc == 2) {
		// search lines from stdin
		search_stream(stdin, argv[1], "<stdin>");
	} else {
		// read from filenames in argv
		for (int i = 2; i < argc; i++) {
			// pathname in argv[i]
			FILE *stream = fopen(argv[i], "r");
			if (stream == NULL) {
				perror(argv[i]);
				exit(1);
			}

			search_stream(stream, argv[1], argv[i]);
		}
	}
}
