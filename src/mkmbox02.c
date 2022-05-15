#include <stdio.h>

#include "aes128.h"
/**
 * @brief SubByteを前計算する
 *
 * @param b
 * @return Affine(inv(b))の結果
 */
unsigned char prep_subB(unsigned char b);

int main() {
	printf("unsigned char mbox02[256]={");
	for (int a = 0x00; a <= 0xff; a++) {
		printf("0x%02x", Multiply(a,0x02));
		if (a != 0xff) printf(",");
	}
	printf("}\n");
}
