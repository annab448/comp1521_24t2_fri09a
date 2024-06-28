#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint16_t a = 0x5555;
	uint16_t b = 0xAAAA;
	uint16_t c = 0x0001;

	printf("a. a | b = 0x%x\n", a | b);
	printf("b. a & b = 0x%x\n", a & b);
	printf("c. a ^ b = 0x%x\n", a ^ b);
	printf("d. a & ~b = 0x%x\n", a & ~b);
	printf("e. c << 6 = 0x%x\n", c << 6);
	printf("f. a >> 4 = 0x%x\n", a >> 4);
	printf("g. a & (b << 1) = 0x%x\n", a & (b << 1));
	printf("h. b | c = 0x%x\n", b | c);
	printf("i. a & ~c = 0x%x\n", a & ~c);

}
