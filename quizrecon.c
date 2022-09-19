#include <ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

void gotoxy(int x, int y);

struct tag_Munje {
   const char* Question;
   const char* Case[3];
    int Answer;
    bool Used;
};
struct Sol {
   short int correct=0;
   short int incorrect=0;
   short int timeout=0;
};

struct tag_Munje Munje[] = {
     {"���� Ÿ���� �⺻���� �ƴ� ����","������", "�迭","������",2,false},
     {"���� �� �ݺ����� �ƴ� ����","switch", "for","while",1,false},
     {"����ü�� ������ �� ����ϴ� Ű�����","int", "goto","struct",3,false},
     {"���� �� ���� ũ�Ⱑ ū Ÿ����","int", "double","char",2,false},
     {"�������� ������ �� ����ϴ� Ű�����","enum", "alias","define",1,false},
     {"���� �� ���� �����ڴ�","++", "?","=",1,false},
     {"���� �迭�� ������ �ٲ� �� ����ϴ� �Լ���","strassign", "strmove","strcpy",3,false},
     {"����ü�� ����� ���� �� ����ϴ� �����ڴ�","->", "*",".",3,false},
     {"������ Ÿ���� �ƴ� ����","unsigned", "short","float",3,false},
     {"C ���α׷����� �ݵ�� �ʿ��� �Լ���","entry", "main","WinMain",2,false},
};

void main()
{
    int num;
    int count;
    int i,j;
    char ch;
    static int cnt=0, cnt2=0, cnt3=0;
    int correct=0, incorrect=1, timeout=0;

    struct Sol p1;

    for (count = 0; count < 5; count++) {// �������� ���� ���� �ϳ��� ����.
        do {
            srand(time(NULL));
            num = rand() % 10;
        } while (Munje[num].Used == true);

        Munje[num].Used = true;

        // ������ ����Ѵ�.

        system("cls");
        gotoxy(2, 2);
        printf("%s?", Munje[num].Question);

        for (i = 0; i < 3; i++) {
            gotoxy(2, 5 + i * 2);
            printf("(%d) %s", i + 1, Munje[num].Case[i]);
        }

        gotoxy(2, 12);
        printf("1,2,3 �� �ϳ��� �����ϼ���.�������� Q : ");

        for (j = 10; j >= 0; j--) {
            Sleep(1000);
            gotoxy(2, 13);
            printf("�����ð� : %d", j);
            if (j < 10) {
                puts(" ");
            }
            if (j <= 0) {
                printf("�ð��ʰ� ������ %d�� �Դϴ�.\n", Munje[num].Answer);
                p1.timeout++;
                ch = _getch();
                while (_kbhit()) {
                    break;
                }
            }
            if (_kbhit() == 1) {
                ch = _getch();
                if (tolower(ch) == 'q') {
                    break;
                }
                ch = ch - '0';
                gotoxy(2, 15);
                if (ch == Munje[num].Answer && j>0) {
                    printf("�����Դϴ�.");
                    p1.correct++;
                    printf("%d", cnt2);
                    break;
                }
                else{
                    printf("Ʋ�Ƚ��ϴ�. ������ %d���Դϴ�.", Munje[num].Answer);
                    p1.incorrect++;
                    break;
                }
            }
        }
        Sleep(1000);
    }
    gotoxy(2, 17);
    printf("%d�� �¾�����, %d�� Ʋ�Ȱ� %d���� �ð��� �ʰ��߽��ϴ�.\n", p1.correct
          ,p1.incorrect,p1.timeout);
    printf("�����ϼ̽��ϴ�.\n");
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}