#include "aes128.h"

void InvShiftRows(unsigned char state[4 * Nb]) {
	unsigned char res[4 * Nb];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < Nb; j++) {
			res[(4 * (j + i) + i) % (4 * Nb)] = state[i + j * 4];
		}
	}

	for (int i = 0; i < 4 * Nb; i++) {
		state[i] = res[i];
	}
}