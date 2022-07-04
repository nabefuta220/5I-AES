#include "aes128.h"

/**
 *
 *
 * この演算って全単射?(全射は確定、単射は?->affineさえ分かれば...!)
 * ->もし全単射でなければそもそもInvSubBytesができないから全単射確定?
 */
void InvSubBytes(unsigned char state[4 * Nb]) {
	unsigned char temp;
	for (int i = 0; i < 4 * Nb; i++) {
		temp     = Affine(state[i]);
		state[i] = Inverse(temp);
	}
}
