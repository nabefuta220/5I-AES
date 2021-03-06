/**
 * @file testInvmixcolumns.c
 * @author Watanabe Satoshi
 * @brief Invmixcolumnsのテスト用プログラム
 * @version 0.1
 * @date 2022-05-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#include "aes128.h"

/**
 * @brief invmixcolumnsの単体テスト用関数
 *
 * @param a
 */
void test_invmixcolumns(unsigned char a[4 * Nb]);
int main() {
	unsigned char a[9][4 * Nb] = {
	    {0x5f, 0x72, 0x64, 0x15, 0x57, 0xf5, 0xbc, 0x92, 0xf7, 0xbe, 0x3b, 0x29,
	     0x1d, 0xb9, 0xf9, 0x1a},
	    {0xff, 0x87, 0x96, 0x84, 0x31, 0xd8, 0x6a, 0x51, 0x64, 0x51, 0x51, 0xfa,
	     0x77, 0x3a, 0xd0, 0x09},
	    {0x4c, 0x9c, 0x1e, 0x66, 0xf7, 0x71, 0xf0, 0x76, 0x2c, 0x3f, 0x86, 0x8e,
	     0x53, 0x4d, 0xf2, 0x56},
	    {0x63, 0x85, 0xb7, 0x9f, 0xfc, 0x53, 0x8d, 0xf9, 0x97, 0xbe, 0x47, 0x8e,
	     0x75, 0x47, 0xd6, 0x91},
	    {0xf4, 0xbc, 0xd4, 0x54, 0x32, 0xe5, 0x54, 0xd0, 0x75, 0xf1, 0xd6, 0xc5,
	     0x1d, 0xd0, 0x3b, 0x3c},
	    {0x98, 0x16, 0xee, 0x74, 0x00, 0xf8, 0x7f, 0x55, 0x6b, 0x2c, 0x04, 0x9c,
	     0x8e, 0x5a, 0xd0, 0x36},
	    {0xc5, 0x7e, 0x1c, 0x15, 0x9a, 0x9b, 0xd2, 0x86, 0xf0, 0x5f, 0x4b, 0xe0,
	     0x98, 0xc6, 0x34, 0x39},
	    {0xba, 0xa0, 0x3d, 0xe7, 0xa1, 0xf9, 0xb5, 0x6e, 0xd5, 0x51, 0x2c, 0xba,
	     0x5f, 0x41, 0x4d, 0x23},
	    {0xe9, 0xf7, 0x4e, 0xec, 0x02, 0x30, 0x20, 0xf6, 0x1b, 0xf2, 0xcc, 0xf2,
	     0x35, 0x3c, 0x21, 0xc7}};

	for (int i = 0; i < 9; i++) {
		test_invmixcolumns(a[i]);
	}
}
void test_invmixcolumns(unsigned char a[4 * Nb]) {
	printf("    ");
	PrintBlock(a);
	InvMixColumns(a);
	printf(" -> ");
	PrintBlock(a);
}