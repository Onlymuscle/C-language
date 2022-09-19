#include<stdio.h>
#include<string.h>

char stradd(char dest[], int src);

void main()
{
	char a[10] = "im";

	stradd(a, 'a');
	printf("%s", a);
}
char stradd(char dest[], int src)
{
	int i = strlen(dest);
	printf("%d", i);
}
