#include "aes128.h"

/**
 * @brief ブロックデータに行列計算をする
 *
 * @param state ブロックデータ
 */
void MixColumns(unsigned char state[4 * Nb]) {
	unsigned char res[4 * Nb];
	for (int i = 0; i < 4 * Nb; i += 4) {
		res[i] = Multiply(0x02, state[i]) ^ Multiply(0x03, state[i + 1]) ^
		         state[i + 2] ^ state[i + 3];
		res[i + 1] = state[i] ^ Multiply(0x02, state[i + 1]) ^
		             Multiply(0x03, state[i + 2]) ^ state[i + 3];
		res[i + 2] = state[i] ^ state[i + 1] ^ Multiply(state[i + 2], 0x02) ^
		             Multiply(state[i + 3], 0x03);
		res[i + 3] = Multiply(0x03, state[i]) ^ state[i + 1] ^ state[i + 2] ^
		             Multiply(0x02, state[i + 3]);
	}
	for (int i = 0; i < 4 * Nb; i++) {
		state[i] = res[i];
	}
}