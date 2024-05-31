#include <stdio.h>

#define MAX_STR_LEN 1000

int main(void) {
	printf("enter a letter: ");
	char c;
	int repeats;
	scanf("%c", &c);
	printf("number of repeats: ");
	scanf("%d", &repeats);

	char str[MAX_STR_LEN];

	for(int i = 0; i < repeats; i++) {
		str[i] = c;
	}

	str[repeats] = '\0';

	printf("%s\n", str);
}
