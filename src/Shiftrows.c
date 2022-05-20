#include "aes128.h"

void ShiftRows(unsigned char state[4 * Nb]) {
	unsigned char temp[4 * Nb];
	for (int i = 0; i < Nb; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i + j * 4] = state[(4 * j + i) % (4 * Nb)];
		}
	}
	for (int i = 0; i < 4 * Nb; i++) {
		state[i] = temp[i];
	}
}
