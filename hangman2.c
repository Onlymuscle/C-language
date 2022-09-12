#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

char* namerand(void);
char* begyo(char a[], char b[]);

void main()
{
	char *name=namerand();
	char cpyna[10];
	int len = strlen(name);
	char ch[2];
	char abc[10];
	int count = 0;
	int k = 0;

	memcpy_s(cpyna, 10, name, len+1);
	memcpy_s(abc, 10, name, len+1);

	for (int i = 0; i < len; i++) {
		abc[i] = '*';
	}

	printf("%s\n", cpyna);

	for (;;) {
		printf("hangman 게임시작 단어는 %d 자리 %d 번째 도전\n", len, count + 1);
		scanf_s("%s", ch,2);
		count++;
		char* a = begyo(cpyna, ch);

		for (int i = 0; i < len; i++) {
			if (a[i] == ch[0]) {
				abc[i] = a[i];
			}
		}

		for (int i = 0; i < len; i++) {
			if (abc[i] == cpyna[i]) {
				k++;
			}
		}

		if (k == len) {
			printf("게임승리\n");
		}
		else if (k != len) {
			k = 0;
		}

		printf("%s\n", abc);
		if (count > 10) {
			system("cls");
			printf("게임실패 정답은 %s\n", name);
		}
	}
}
char* namerand(void)// 단어 랜덤
{
	char* a[] = { "chrome","steam","genshin","closers","unityhub" };

	int i;

	srand(time(NULL));
	i = rand() % 5;

	return a[i];
}
char* begyo(char a[], char b[])
{
	char* arr = (char*)malloc(sizeof(char) * 10);

	for (int i = 0; i < sizeof(arr); i++) {

		if (a[i] == b[0]) {
			arr[i] = a[i];
		}
	}
	return arr;
	free(arr);
}