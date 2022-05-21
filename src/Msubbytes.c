#include "aes128.h"

/**
 * @brief 各バイトデータに逆元をとり、アフィン変換を取る
 *
 * @param state バイトデータ
 */
void SubBytes(unsigned char state[4 * Nb]) {
	unsigned char temp;
	for (int i = 0; i < 4 * Nb; i++) {
		temp     = Inverse(state[i]);
		state[i] = Affine(temp);
	}
}