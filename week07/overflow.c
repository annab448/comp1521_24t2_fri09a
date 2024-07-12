#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint16_t x = 30000u + 30000u;
	printf("30000 + 30000 = %d\n", (unsigned) x);
}
