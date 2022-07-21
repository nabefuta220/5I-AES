/**
 * @file Finverse.c
 * @author Watanabe Satoshi
 * @brief inverseを繰り返し二乗法を用いて高速化したプログラム
 * @version 0.1
 * @date 2022-05-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "aes128.h"

/**
 * @brief a^n(mod x^8 + x^4 + x^3 + x + 1)を求める
 *
 * @param a
 * @param n
 * @return unsigned char a^n(mod x^8 + x^4 + x^3 + x + 1)
 */
unsigned char modpow(unsigned char a, int n);

unsigned char Inverse(unsigned char b) { return modpow(b, 254); }

unsigned char modpow(unsigned char a, int n) {
	unsigned char res = 1;

	if (n == 0) {
		return res;
	}
	res = modpow(a, n / 2);
	res = Multiply(res, res);
	if (n & 1) {
		res = Multiply(res, a);
	}
	return res;
}