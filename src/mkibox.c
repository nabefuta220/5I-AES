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
	printf("unsigned char ibox[255]={");
	for (unsigned char i = 0;; i++) {
		// printf("%x : %x\n", i, Inverse(i));
		printf("0x%02x", Inverse(i));
		if (i != 0-1) {
			printf(", ");
		}else{
			break;
		}
	}
	printf("};\n");
}