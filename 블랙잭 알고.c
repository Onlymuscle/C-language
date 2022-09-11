#include<stdio.h>
#include<malloc.h>

void main()
{
	int i, j,k;
	
	scanf_s("%d", j);

	i = (int*)malloc(j * sizeof(int));
	
	for (k = 0; k < sizeof(int); k++) {
		i[k] =  1 + k ;
	}

	for (k = 0; k < sizeof(j); k++) {
		printf("i[%d]=%d",k,i[k])
	}
}