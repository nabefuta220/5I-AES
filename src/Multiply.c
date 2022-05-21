#include "aes128.h"

/**
 * @brief 2つのバイトデータの積をmod(x^8 + x^4 + x^3 + x^2 +1)で求める
 *
 * @param x バイトデータ1
 * @param y バイトデータ2
 * @return unsigned char x・y(mod x^8 + x^4 + x^3 + x^2 +1)
 */
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