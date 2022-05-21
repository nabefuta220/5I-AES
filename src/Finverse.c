/**
 * @file Finverse.c
 * @author Watanabe Satoshi
 * @brief inverseをアフィン変換を用いて高速化したプログラム
 * @version 0.1
 * @date 2022-05-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "aes128.h"
#include "ibox.c"

unsigned char Inverse(unsigned char b) {
	unsigned char res = 0;

	for (int i = 0; i < 8; i++) {
        if( b & (1<<i)){
			res ^= ibox[i];
		}
	}
	return res;
}