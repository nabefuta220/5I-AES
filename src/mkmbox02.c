/**
 * @file mkmbox02.c
 * @author Watanabe Satoshi
 * @brief mixcolumnsの高速化用辞書を作成する
 * @version 0.1
 * @date 2022-05-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#include "aes128.h"

int main() {
	printf("unsigned char mbox02[256]={");
	for (int a = 0x00; a <= 0xff; a++) {
		printf("0x%02x", Multiply(a, 0x02));
		if (a != 0xff) printf(",");
	}
	printf("};\n");
}
