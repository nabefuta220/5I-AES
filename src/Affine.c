#include "aes128.h"
// ジャンさんがやった5つに分ける方法でもやってみたい

unsigned char Affine(unsigned char b) {
	unsigned char res  = 0;
	unsigned char mask = 0b10001111;
	for (int i = 0; i < 8;i++){
		res ^= (b & mask);
		mask = mask >> 1 | ((mask&(1<<0))<<7 );
	}
	res ^= 0b11000110;
	return res;
}