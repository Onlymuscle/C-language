#include<stdio.h>
#include<windows.h>

extern int i = 0;

void Count();

void main()
{
	printf("시간 흐르는중...:\n");
	for (;;) {
		Sleep(1000);
		Count();
		i++;
		printf("%d초 지났습니다.\r",i);
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
		printf("%d시간 %d 분이 지났습니다.\n", hour, minutes);
	}
}