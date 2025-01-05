#include <stdio.h>

#define ASCIICHARNUM 128

int isUnique(char *string, int length) {
	int letters[ASCIICHARNUM] = {0};

	for (int i=0; i<length; i++) {
		if (0 < letters[string[i]]) {
			return -1;
		}
		letters[string[i]]++;
	}
	return 0;
}

int main(void) {
	int length;
	scanf("%d", &length);

	char string[length];
	scanf("%s", string);

	if (0 == isUnique(string, length)) {
		printf("%s is Unique\n", string);
	}
	else {
		printf("%s is not Unique\n", string);
	}
	return 0;
}