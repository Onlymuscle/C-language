#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, result;

	i = 1000;
	j = 0;
	result = 0;

	for (j; j < i; j++) { //j�� i���� Ŀ��������  j=j+1
		result += j; // result=result+j;
		if (result > 1000) {
			break;
		}
	}
	printf(" ���������� ���� ���� = %d, ������= %d \n", j, result);
}