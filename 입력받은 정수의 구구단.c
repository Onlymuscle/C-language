#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i, j, k;

		printf("������ ���\n");
	scanf_s("%d", &i);

	for (j = 1; j <= 9; j = j + 1) {
		printf(" % d * %d = %d\n", i, j, k = i * j);
	}
}