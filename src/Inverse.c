#include "aes128.h"

unsigned char Inverse(unsigned char b) {
	unsigned char res=1;
	int pow = 254;
	for (int i = 0; i < pow;i++){
		res = Multiply(res, b);
	}
	return res;
}
