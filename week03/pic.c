#include <stdio.h>

#define PIC_HEIGHT 4
#define PIC_WIDTH 3
char picture[4][3] = {{'*', ' ', '*'},
					{' ', '*', ' '},
					{' ', '*', '*'},
					{'*', '*', '*'} };

int main(void) {
	for (int row = 0; row < PIC_HEIGHT; row++) {
		for (int col = 0; col < PIC_WIDTH; col++) {
			printf("%c", picture[row][col]);
		}
		printf("\n");
	}

	return 0;
}
