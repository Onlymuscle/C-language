#include<stdio.h>
#include<stdlib.h>

#define True 1

void main()
{
	int i = 0, j = 0;

	while (True) {
		if (i == 30) {
			break; //i ���� 30�̵Ǹ� break
		}
		i = i + 1; // i���� 1�� ���ϰ�
		j = 2 * i; // j���� 2*i��
		if (i <= 10) { //10�� i���� ũ�ų� ������ ���
			printf("1 ~ 10������ 2i ���� %d \n", j);
		}
		if (i > 10 && i < 21) { //i ���� 10���� ũ�ų� 21�� i ������ ������ ���
			j = 3 * i; //j���� 3*j ��
			printf("11 ~ 20 ������ 3i �� %d \n", j);
		}
		if (i >= 21 && i <= 30) {
			printf("21 ~ 30 ������ 2i �� %d \n", j);
		}
	}
}



