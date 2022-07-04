/**
 * @file testInvsubbyte.c
 * @author Watanabe Satoshi
 * @brief Invsubbyteのテスト用プログラム
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include "aes128.h"
int main() {
	unsigned char res[4 * Nb];
	printf("  |00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
	printf("--+-----------------------------------------------\n");
	for (int i = 0; i < 0x100; i += 0x10) {
		printf("%02x|", i);
		for (int j = 0; j < 0x10; j++) {
			res[0] = i + j;
			InvSubBytes(res);
			printf("%02x", res[0]);
			if (j != 0x0f) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}
}