#include<stdio.h>
#include<windows.h>

extern int i = 0;

void Count();

void main()
{
	printf("�ð� �帣����...:\n");
	for (;;) {
		Sleep(1000);
		Count();
		i++;
		printf("%d�� �������ϴ�.\r",i);
	}
}
void Count()
{
	static int count,minutes,hour;
	count++;
	
	if (0 == count % 60)
	{
		i = 0;
		minutes++;
		if (0 == count % 3600) {
			hour++;
			system("cls");
			minutes = 0;
		}
		system("cls");
		printf("%d�ð� %d ���� �������ϴ�.\n", hour, minutes);
	}
}