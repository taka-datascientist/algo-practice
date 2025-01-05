#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/* 解けなかったため、解答を模写 */

bool oneEditReplace(char *str1, char *str2) {
	bool foundDifference = false;
	if (strlen(str1) != strlen(str2)) {
		return false;
	}

	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] != str2[i]) {
			if (foundDifference) {
				return false;
			}
			
			foundDifference = true;
		}
	}

	return true;
}

bool oneEditInsert(char *str1, char *str2) {
	int index1 = 0;
	int index2 = 0;

	while (index2 < strlen(str2) && index1 < strlen(str1)) {
		if (str1[index1] != str2[index2]) {
			if (index1 != index2) {
				return false;
			}
			index2++;
		} else {
			index1++;
			index2++;
		}
	}
	return true;
}

bool oneEditAway(char *str1, char *str2) {
	if (strlen(str1) == strlen(str2)) {
		return oneEditReplace(str1, str2);
	} else if (strlen(str1) + 1 == strlen(str2)) {
		return oneEditInsert(str1, str2);
	} else if (strlen(str1) - 1 == strlen(str2)) {
		return oneEditInsert(str2, str1);
	}
	return false;
}

int main(int argc, char const *argv[]) {
	char str1[100] = {'\0'};
	char str2[100] = {'\0'};
	scanf("%s", str1);
	scanf("%s", str2);

	if (oneEditAway(str1, str2)) {
		printf("%s, %s -> true\n", str1, str2);
	} else {
		printf("%s, %s -> false\n", str1, str2);
	}
	return 0;
}

