#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 入力文字列長は128以下を前提とする */

int main(int argc, char const *argv[])
{
	char pos = ' ';
	int cnt = 1;
	char str[128+1] = {'\0'};

	printf("Enter str : ");
	scanf("%s", str);
	
	/* ToDo */
	/* 入力文字列長が128を超える場合のガード処理を追加する */

	pos = str[0];
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == str[i+1])　{
			cnt++;
		}
		else {
			printf("%c%d", pos, cnt);
			pos = str[i+1];
			cnt = 1;
		}
	}
	puts("");

	return 0;
}