#include <stdio.h>

#include "aes128.h"
#include "sbox.c"
/**
 * @brief sboxから Invsubbyteを前計算する
 *
 * @param b
 * @return Affine(inv(b))の結果
 */

int main() {
	unsigned char isbox[256];
	for (int i = 0; i < 0x100;++i){
		isbox[sbox[i]] = i;
	}
	printf("unsigned char isbox[256]={");
	for (unsigned char i = 0;; i++) {
		
		printf("0x%02x",isbox[i]);
		if (i != 0xff) {
			printf(", ");
		} else {
			break;
		}
	}
	printf("};\n");
}
