#include "aes128.h"

void InvSubBytes(unsigned char state[4 * Nb]) {
	unsigned char temp;
	for (int i = 0; i < 4 * Nb; i++) {
		temp     = Affine(state[i]);
		state[i] = Inverse(temp);
	}
}