#include<stdio.h>

int Power(int a, int b);

void main()
{
	int a , b , sum;

	printf("�� ���� �Է����ּ��� \n");
	scanf_s(" %d%d",&a,&b);
	sum=Power(a, b);
	printf("%d", sum);
}
int Power(int a, int b) {
	int d=a;
	
	for (int c =1; c < b; ++c) {
		d = d * a;
	}
	return d;
}
