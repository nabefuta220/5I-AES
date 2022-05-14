#include "aes128.h"

unsigned char Multiply(unsigned char x, unsigned char y) {
	unsigned char z = 0;
	while (y != 0) {
		if (y & (1 << 0)) {
			z ^= x;
		}
		y >>= 1;
		if (x & (1 << 7)) {
			x <<= 1;
			x ^= (0x1B);
		} else {
			x <<= 1;
		}
	}
	return z;
}