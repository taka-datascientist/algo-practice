#include <stdio.h>
#include <string.h>

void convertSpace(char *str, int length) {
	int spacecnt = 0, i, index;

	for (i=0; i<length; i++) {
		if (' ' == str[i]) {
			spacecnt++;
		}
	}

	index = length + spacecnt * 2;

	str[index] = '\0';
	for (i=length-1; i>=0; i--) {
		if (' ' != str[i]) {
			str[index-1] = str[i];
			index--;
		}
		else {
			str[index-1] = '0';
			str[index-2] = '2';
			str[index-3] = '%';
			index -= 3;
		}
	}
}

int main(void) {
	char str[1000] = {'\0'};
	int length = 0;

	//scanf("%s", str);
	//scanf("%d", &length);

	memcpy(str, "test ", 5);
	length = 5;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	memcpy(str, "t e s t  ", 9);
	length = 9;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	memcpy(str, "t   e  s t ", 11);
	length = 11;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	return 0;
}