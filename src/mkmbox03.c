#include <stdio.h>

#include "aes128.h"

int main() {
	printf("unsigned char mbox03[256]={");
	for (int a = 0x00; a <= 0xff; a++) {
		printf("0x%02x", Multiply(a, 0x03));
		if (a != 0xff) printf(",");
	}
	printf("};\n");
}
