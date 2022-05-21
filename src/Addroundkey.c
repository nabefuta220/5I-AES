#include "aes128.h"

/**
 * @brief
 * ブロックをワードデータからなる1次元配列と見て、ワードごとにラウンド鍵をxorをとる
 *
 * @param state ブロック
 * @param w ラウンド鍵
 */
void AddRoundKey(unsigned char state[4 * Nb], unsigned long int w[Nb]) {
	key_t s;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s.byte[j] = state[i * 4 + j];
		}
		s.word ^= w[i];
		for (int j = 0; j < 4; j++) {
			state[i * 4 + j] = s.byte[j];
		}
	}
}