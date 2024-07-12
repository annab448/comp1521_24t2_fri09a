

uint32_t six_middle_bits(uint32_t u) {
	return (u >> 13) & 0x3F;
}
