#include<stdio.h>
#include<ctype.h>
#include<string.h>

char* conen(char a[]);

void main()
{
	char a[10];

	printf("���� �Է�:\n");
	scanf_s("%s", a,10);

	char* b = conen(a);

	printf("%s", b);
}
char* conen(char a[])
{
	char alp[26];
	char alpb[26];
	
	for (int i = 0; i < sizeof(alp); i++) {
		alp[i] = 65 + i; //�ҹ���
		alpb[i] = 97 + i; //�빮��
	}

	for (int i = 0; i < sizeof(alp); i++) {
		for(int j=0;j < 10 ;j++){
			if (alp[i] == a[j]) { //j==J
				a[j] = 97 + i;//�빮�� J�� �ҹ��� j�� �ٲ��
			}
			else if (alpb[i] == a[j]) {
				a[j] = 65 + i;
			}
		}
	}
	return a;
}