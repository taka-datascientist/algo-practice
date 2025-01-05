#include <stdio.h>
#include <limits.h>

/* ビット演算子の確認用                                                  */
/* ビットを反転させるプログラムとして、参考書では以下のtoggle()が紹介されていた。  */
/* しかし、上記以外の方法として1との排他的論理和をとれば十分ではないかと思ったため、 */
/* 動作確認を行う。                                                     */

/* 整数のiビット目を切り替える */
int toggle(int bitVector, int index) {
	int mask = 1 << index;

	if (0 > index) {
		return bitVector;
	}

	if (0 == (bitVector & mask)) {
		bitVector |= mask;
	}
	else {
		bitVector &= ~mask;
	}

	return bitVector;
}

int bitMirror(int bitVector, int index) {
	int mask = 1 << index;

	if (0 > index) {
		return bitVector;
	}

	return bitVector ^ mask;
}

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void putb(unsigned int v) {
  putchar('0'), putchar('b'), printb(v), putchar('\n');
}

int main(int argc, char const *argv[])
{
	int number, index;

	printf("Enter number : ");
	scanf("%d", &number);
	printf("Enter index  : ");
	scanf("%d", &index);

	printf("number(Hex)       : ");
	putb(number);
	printf("toggle(number)    : ");
	putb(toggle(number, index));
	printf("bitMirror(number) : ");
	putb(bitMirror(number, index));

	
	return 0;
}