/**
 * @file Mixcolumns.c
 * @author Watanabe Satoshi
 * @brief mixcolumnsを前計算を用いて高速化したプログラム
 * @version 0.1
 * @date 2022-05-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "aes128.h"
#include "mbox02.c"
#include "mbox03.c"

void MixColumns(unsigned char state[4 * Nb]) {
	unsigned char res[4 * Nb];
	for (int i = 0; i <= 12; i += 4) {
		res[i] = mbox02[state[i]] ^ mbox03[state[i + 1]] ^ state[i + 2] ^
		         state[i + 3];
		res[i + 1] = state[i] ^ mbox02[state[i + 1]] ^ mbox03[state[i + 2]] ^
		             state[i + 3];
		res[i + 2] = state[i] ^ state[i + 1] ^ mbox02[state[i + 2]] ^
		             mbox03[state[i + 3]];
		res[i + 3] = mbox03[state[i]] ^ state[i + 1] ^ state[i + 2] ^
		             mbox02[state[i + 3]];
	}
	for (int i = 0; i <= 4 * Nb; i++) state[i] = res[i];
}