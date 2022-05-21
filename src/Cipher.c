#include <stdio.h>

#include "aes128.h"
/**
 * @brief 平文をAES128で暗号化する
 *
 * @param in 平文
 * @param out 暗号化した平文
 * @param w 暗号鍵
 */
void Cipher(unsigned char in[4 * Nb], unsigned char out[4 * Nb],
            unsigned long int w[Nb * (Nr + 1)]) {
	printf("PLAINTEXT:       ");
	PrintBlock(in);
	printf("KEY:             ");
	PrintKey(w);
	printf("CIPHER (ENCRIPT):\n");
	for (int i = 0; i < 4 * Nb; i++) {
		out[i] = in[i];
	}
	printf("round[%2d].input  ", 0);
	PrintBlock(out);

	AddRoundKey(out, w);
	printf("round[%2d].k_sch  ", 0);
	PrintKey(w);

	for (int round = 0; round < Nr; round++) {
		printf("round[%2d].start  ", round + 1);
		PrintBlock(out);

		SubBytes(out);
		printf("round[%2d].s_box  ", round + 1);
		PrintBlock(out);

		ShiftRows(out);
		printf("round[%2d].s_row  ", round + 1);
		PrintBlock(out);

		if (round != Nr - 1) {
			MixColumns(out);
			printf("round[%2d].m_col  ", round + 1);
			PrintBlock(out);
		}
		AddRoundKey(out, (long unsigned int *)(w + Nb * (round + 1)));
		printf("round[%2d].k_sch  ", round + 1);
		PrintKey((long unsigned int *)(w + Nb * (round + 1)));
	}
	printf("round[%2d].output ", 10);
	PrintBlock(out);
}