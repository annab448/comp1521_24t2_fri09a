#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int num = atoi(argv[1]);
	int dec = 100;
	int hex = 0x64;
	int oct = 0144;
	int bin = 0b011001000;

	printf("%d = 0%3o = 0x%2x\n", num, num, num);
}
