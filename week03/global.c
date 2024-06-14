#include <stdio.h>

int x = 8;
int y = 7;
int z = 10;
int ans;

int main(void) {
	ans = ((x*x + y*y) - x*y) * z;
	printf("%d\n", ans);
	return 0;

}
