#include "aes128.h"

void AddRoundKey(unsigned char state[4 * Nb], unsigned long int w[Nb]) {
	key_t s;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s.byte[j] = state[i * 4+j];
		}
		s.word ^= w[i];
		state[i] = s.word;
	}
}