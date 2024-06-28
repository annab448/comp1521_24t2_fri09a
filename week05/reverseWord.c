#include <stdio.h>

#define WORD_BITS 32

typedef unsigned int Word;

Word reverseBits(Word w);

int main(void) {
	// 0000 0001 0010 0011 0100 0101 0110 0111
	Word w1 = 0x01234567;
	printf("    word = 0x%x\n", w1);
	printf("reversed = 0x%x\n", reverseBits(w1));
}

Word reverseBits(Word w) {
	Word ret = 0;
	for (int i = 0; i < WORD_BITS; i++) {
		Word wMask = 1u << i;
		if (w & wMask) {
			Word retMask = 1u << (WORD_BITS-i-1);
			ret = ret | retMask;
		}
	}
	return ret;
}
