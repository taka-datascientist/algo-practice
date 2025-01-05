#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[], int length) {
	int letters[128] = {0};
	int duplicationcount = 0;
	int i = 0;

	for (i = 0; i < length; i++) {
		if (' ' == str[i]) {
			continue;
		}
		//printf("str[i]=%c\n", str[i]);
		if (0 != letters[str[i]]) {
			letters[str[i]]--;
		}
		else {
			letters[str[i]]++;
		}
	}

	for (i = 0; i < 128; i++) {
		duplicationcount += letters[i];
	}
	//printf("duplicationcount=%d\n", duplicationcount);
	if (1 >= duplicationcount) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	if (isPalindrome("tact coa", 8)) {
		printf("true\n");		
	}
	else {
		printf("false\n");
	}
	return 0;
}