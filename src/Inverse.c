#include "aes128.h"

/**
 * @brief mod(x^8 + x^4 + x^3 + x^2 +1)でのバイトデータの逆元を取る
 *
 * @param b バイトデータ
 * @return unsigned char b^-1の値
 */
unsigned char Inverse(unsigned char b) {
	unsigned char res = 1;
	int pow           = 254;
	for (int i = 0; i < pow; i++) {
		res = Multiply(res, b);
	}
	return res;
}
