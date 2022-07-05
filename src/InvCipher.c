#include <stdio.h>

#include "aes128.h"
void InvCipher(unsigned char in[4 * Nb], unsigned char out[4 * Nb],
               unsigned long int w[Nb * (Nr + 1)]) {
	printf("INVERSE CIPHER (DECRYPT):\n");
	for (int i = 0; i < 4 * Nb; i++) {
		out[i] = in[i];
	}
	printf("round[%2d].iinput  ", 0);
	PrintBlock(out);

	AddRoundKey(out, (long unsigned int *)(w + Nb * Nr));
	printf("round[%2d].ik_sch  ", 0);
	PrintKey((long unsigned int *)(w + Nb * Nr));

	for (int round = 0; round < Nr; round++) {
		printf("round[%2d].istart  ", round + 1);
		PrintBlock(out);

		InvShiftRows(out);
		printf("round[%2d].is_row  ", round + 1);
		PrintBlock(out);

		InvSubBytes(out);
		printf("round[%2d].is_box  ", round + 1);
		PrintBlock(out);

		printf("round[%2d].ik_sch  ", round + 1);
		PrintKey((long unsigned int *)(w + Nb * (Nr - round-1 )));

		AddRoundKey(out, (long unsigned int *)(w + Nb * (Nr - round-1 )));
	

		if (round != 9) {
			printf("round[%2d].ik_add  ", round + 1);
			PrintBlock(out);
			InvMixColumns(out);
		}
	}
	printf("round[%2d].ioutput ", 10);
	PrintBlock(out);
}