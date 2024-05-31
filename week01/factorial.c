#include <stdio.h>
#include <stdlib.h>

int fac(int num) {
	// should I stop?
	if (num <= 1) {
		return 1;
	}
	num = num * fac(num - 1);
	return num;
}

int main(int argc, char *argv[]) {
	int num = atoi(argv[1]);

	int f = fac(num);
	printf("%d\n", f);	
}
