#include "aes128.h"

void Cipher(unsigned char in[4 * Nb], unsigned char out[4 * Nb],
            unsigned long int w[Nb * (Nr + 1)]) {
	//unsigned char state[4*Nb];
	for (int i = 0; i < 4 * Nb; i++) {
		out[i] = in[i];
	}
	AddRoundKey(out, w);
	for (int round = 0; round < Nr;round++){
		SubBytes(out);
		ShiftRows(out);
        if(round != Nr-1){
			MixColumns(out);
		}
		AddRoundKey(out, (long unsigned int *)(w + Nb * round));
	}
}