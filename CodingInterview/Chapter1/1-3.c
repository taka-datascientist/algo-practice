#include <stdio.h>
#include <string.h>

void convertSpace(char *str, int length) {
	char convstr[1000] = {' '};

	for (int i=0, j=0; i<length; i++, j++) {
		if (' ' != str[i]) {
			convstr[j] = str[i];
		}
		else {
			memcpy(&convstr[j], "%20", 3);
			j+= 2;
		}
	}
	memcpy(str, convstr, 1000);
}

int main(void) {
	char str[1000] = {'\0'};
	int length = 0;

	//scanf("%s", str);
	//scanf("%d", &length);

	memcpy(str, "test ", 5);
	length = 4;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	memcpy(str, "t e s t  ", 9);
	length = 8;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	memcpy(str, "t   e  s t ", 11);
	length = 10;
	printf("str(Plane)   = %s\n", str);
	convertSpace(str, length);
	printf("str(Convert) = %s\n", str);
	memset(str, '\0', 1000);

	return 0;
}