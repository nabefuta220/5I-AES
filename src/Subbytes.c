/**
 * @file Subbytes.c
 * @author Watanabe Satoshi
 * @brief subbytesを前計算を用いて高速化したプログラム
 * @date 2022-05-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "aes128.h"
#include "sbox.c"
void SubBytes(unsigned char state[4 * Nb]) {
	for (int i = 0; i <= 4 * Nb - 1; i++) {
		state[i] = sbox[state[i]];
	}
}