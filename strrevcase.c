#include<stdio.h>
#include<ctype.h>
#include<string.h>

char* conen(char a[]);

void main()
{
	char a[10];

	printf("영어 입력:\n");
	scanf_s("%s", a,10);

	char* b = conen(a);

	printf("%s", b);
}
char* conen(char a[])
{
	char alp[26];
	char alpb[26];
	
	for (int i = 0; i < sizeof(alp); i++) {
		alp[i] = 65 + i; //소문자
		alpb[i] = 97 + i; //대문자
	}

	for (int i = 0; i < sizeof(alp); i++) {
		for(int j=0;j < 10 ;j++){
			if (alp[i] == a[j]) { //j==J
				a[j] = 97 + i;//대문자 J를 소문자 j로 바꿔라
			}
			else if (alpb[i] == a[j]) {
				a[j] = 65 + i;
			}
		}
	}
	return a;
}