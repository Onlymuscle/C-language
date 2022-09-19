#include<stdio.h>
#include<string.h>

void main()
{
	char a[10] = "as";
	char b[10] = "dj";

	strncpy_s(a, sizeof(10),b);

	printf("%s", a);
}