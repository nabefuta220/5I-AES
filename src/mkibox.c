/**
 * @file mkibox.c
 * @author Watanabe Satoshi
 * @brief inverse関数の高速化用の辞書の作成プログラム
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#include "aes128.h"
int main() {
	printf("unsigned char ibox[8]={");
	for (unsigned char i = 1; i != 0; i <<= 1) {
		// printf("%x : %x\n", i, Inverse(i));
		printf("0x%02x", Inverse(i));
		if (i != 1 << 7) {
			printf(", ");
		}
	}
	printf("};\n");
}