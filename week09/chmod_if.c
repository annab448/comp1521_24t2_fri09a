#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void chmod_if_needs(char *path) {
	struct stat info;
	if (stat(path, &info) != 0) {
		perror(path);
		exit(1);
	}

	mode_t mode = info.st_mode;
	if (mode & S_IWOTH) {
		// it's writeable!!
		printf("changing %s\n", path);
		mode = mode & (~S_IWOTH);
		chmod(path, mode);
	} else {
		printf("%s not public write\n", path);
	}

}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s file1, file2, ...\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		// path to chekc in argv[i]
		chmod_if_needs(argv[i]);
	}
}
