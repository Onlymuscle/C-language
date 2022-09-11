#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

char* randomword(void);

char* strcmpword(char a[], char b[]);

int cmp_a(char a[],char b[]);

void main()
{
	char word[10];
	char static cmpword[10];
	int count = 0;
	char cp_word[10];
	char chipal[20]={0,};
	int i = 0,f=0;
	int d = 0;

	memcpy(word, randomword(), sizeof(word));
	printf("%s", word);
	printf("단어를 입력하세요:\n");
a:

	for (;;) {

		scanf_s("%s", cmpword, 10);

		for (int j = 0; j < sizeof(chipal); j++) {
			if (chipal[j] == 0) {
				chipal[j] = cmpword[0];
				printf("%c\n", chipal[j]);
				i = j;
				break;
				
			}
		}
		if (i != 0) {
			for (i = 0; i < sizeof(chipal); i++) {
				if (chipal[i] == cmpword[0]) {
					printf("중복되거나 이미 입력된 단어입니다.\n");
					goto a;
				}
			}
		}
		strcmpword(word, cmpword);

		char* ch = strcmpword(word, cmpword);

		for (int i = 0; i < sizeof(cmpword); i++) {
			cp_word[i] = ch[i];

			if (ch[i] == '\0') {
				ch[i] = '0';
				break;
			}
		}
		
			int k = strlen(cmpword);

			if (k == 1) {
				for (int i = 0; i < sizeof(word); i++) {
					d = cmp_a(word[i], cmpword[i]);

					if (word[i] == '\0' && cmpword[i] == '\0') {
						break;
					}

					if (d == 1) {
						f += 1;
					}
					else {
						f -= 1;
					}
				}
				if (strlen(word) == f) {
					printf("승리");
				}
				else if (strlen(word) != f) {
					count++;

					printf("%d 회차\n", count);
					printf("%s\n", cp_word);
				}
				f = 0;

				if (count >= 7) {
					system("cls");
					printf("게임오버 정답은 %s 입니다.", word);
					goto a;
				}
			}
			else {
				printf("중복되거나 이미 입력된 단어입니다.\n");
				goto a;
			}
	}
}
char* randomword(void)
{
	int i;

	srand(time(NULL));
	i = rand() % 4;

	if (i == 0) {
		static char word[10] = "malloc";

		return word;
	}
	if (i == 1) {
		static char word[10] = "apple";

		return word;
	}
	if(i == 2) {
		static char word[10] = "grace";

		return word;
	}
	if (i == 3) {
		static char word[10] = "lostark";
		
		return word;
	}
}
char* strcmpword(char a[], char b[])
{
	char(*p) = (char*)malloc(10 * sizeof(char)); //사본 작성
	int k;
	char(*str) = (char*)malloc(10 * sizeof(char));

	for (int i = 0; i < strlen(a); i++) {
		p[i] = a[i];

		if (p[i] == NULL) {
			free(p);
		}
	}

	for (int i = 0; i < sizeof(p); i++) {

		for (int j = 0; j < sizeof(p); j++) {

			if (a[i] == b[j]) {
				str[i] = a[i];
			}
		}
		if (str[i] != a[i]) {
			str[i] = '*';
		}
		
	}

	return str;

	free(str);
	free(p);
}
int cmp_a(char a[], char b[])
{

		if (a == b) {
			return 1;
		}
		else {
			return 0;
		}
}
