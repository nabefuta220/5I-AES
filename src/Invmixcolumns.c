#include "aes128.h"

void InvMixColumns(unsigned char state[4 * Nb]) {
	unsigned char temp[4 * Nb];

	for (int i = 0; i < Nb * 4; i += 4) {
		temp[i] = Multiply(state[i], 0x0e) ^ Multiply(state[i + 1], 0x0b) ^
		          Multiply(state[i + 2], 0x0d) ^ Multiply(state[i + 3], 0x09);
		temp[i + 1] = Multiply(state[i], 0x09) ^ Multiply(state[i + 1], 0x0e) ^
		              Multiply(state[i + 2], 0x0b) ^
		              Multiply(state[i + 3], 0x0d);
		temp[i + 2] = Multiply(state[i], 0x0d) ^ Multiply(state[i + 1], 0x09) ^
		              Multiply(state[i + 2], 0x0e) ^
		              Multiply(state[i + 3], 0x0b);
		temp[i + 3] = Multiply(state[i], 0x0b) ^ Multiply(state[i + 1], 0x0d) ^
		              Multiply(state[i + 2], 0x09) ^
		              Multiply(state[i + 3], 0x0e);
	}
	for (int i = 0; i < Nb * 4; i++) {
		state[i] = temp[i];
	}
}