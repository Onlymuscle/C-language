#include<stdio.h>
#include<string.h>

struct tag_friend {
	char name[10];
	int age;
	double height;
};
void main()
{
	struct tag_friend p1 = { "�����",25,181.1 };
	outfri(friend);
}
void outfri(struct a)
{
	printf("�̸� = %s , ���� = %d , Ű = %.1f\n".a.name, a.age, a.height);
}