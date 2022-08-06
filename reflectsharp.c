#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void main()
{
	int x = 1, y = 1, i;

	system("cls");

	for (;;) {
		if (_kbhit()) {
			i = _getch();
			Sleep(20);
			system("cls");

			switch (i) {
			case '7':
				gotoxy(x--, y--);
				putchar('#');
				break;
			case '1':
				gotoxy(x--, y++);
				putchar('#');
				break;
			case '3':
				gotoxy(x++, y++);
				putchar('#');
				break;
			case '9':
				gotoxy(x++, y--);
				putchar('#');
				break;
			case '-':
				exit(1);
				break;
			}
			if (x == 50) {
				x = x - 2, y--;
				putchar('#');
			}
			else if (y == 25) {
				x--, y = y - 2;
				putchar('#');
			}
			else if (x == 0) {
				x = x + 2, y--;
				putchar('#');
			}
			else if (y == 0) {
				x--, y = y + 2;
				putchar('#');
			}
		}
	}
}