#include "aes128.h"

/**
 * @brief bits分、右にローテートする
 *
 * @param a
 * @param bits ローテートする回数
 * @return aをbits分、右にローテートした結果
 **/
unsigned char rotate(unsigned char a, int bits);
/**
 * @brief バイトデータに対してアフィン変換を行う
 *
 * @param b バイトデータ
 * @return unsigned char bにアフィン変換を行った結果
 */
unsigned char Affine(unsigned char b) {
	unsigned char res = b;
	res ^= rotate(b, 4);
	res ^= rotate(b, 5);
	res ^= rotate(b, 6);
	res ^= rotate(b, 7);
	res ^= 0b01100011;
	return res;
}

unsigned char rotate(unsigned char a, int bits) {
	bits %= 8;
	return (a >> bits) ^ (a << (8 - bits));
}