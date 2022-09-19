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
     {"다음 타입중 기본형이 아닌 것은","정수형", "배열","문자형",2,false},
     {"다음 중 반복문이 아닌 것은","switch", "for","while",1,false},
     {"구조체를 선언할 때 사용하는 키워드는","int", "goto","struct",3,false},
     {"다음 중 가장 크기가 큰 타입은","int", "double","char",2,false},
     {"열거형을 선언할 때 사용하는 키워드는","enum", "alias","define",1,false},
     {"다음 중 단항 연산자는","++", "?","=",1,false},
     {"문자 배열의 내용을 바꿀 때 사용하는 함수는","strassign", "strmove","strcpy",3,false},
     {"구조체의 멤버를 읽을 때 사용하는 연산자는","->", "*",".",3,false},
     {"정수형 타입이 아닌 것은","unsigned", "short","float",3,false},
     {"C 프로그램에서 반드시 필요한 함수는","entry", "main","WinMain",2,false},
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

    for (count = 0; count < 5; count++) {// 출제되지 않은 문제 하나를 고른다.
        do {
            srand(time(NULL));
            num = rand() % 10;
        } while (Munje[num].Used == true);

        Munje[num].Used = true;

        // 문제를 출력한다.

        system("cls");
        gotoxy(2, 2);
        printf("%s?", Munje[num].Question);

        for (i = 0; i < 3; i++) {
            gotoxy(2, 5 + i * 2);
            printf("(%d) %s", i + 1, Munje[num].Case[i]);
        }

        gotoxy(2, 12);
        printf("1,2,3 중 하나를 선택하세요.끝낼때는 Q : ");

        for (j = 10; j >= 0; j--) {
            Sleep(1000);
            gotoxy(2, 13);
            printf("남은시간 : %d", j);
            if (j < 10) {
                puts(" ");
            }
            if (j <= 0) {
                printf("시간초과 정답은 %d번 입니다.\n", Munje[num].Answer);
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
                    printf("정답입니다.");
                    p1.correct++;
                    printf("%d", cnt2);
                    break;
                }
                else{
                    printf("틀렸습니다. 정답은 %d번입니다.", Munje[num].Answer);
                    p1.incorrect++;
                    break;
                }
            }
        }
        Sleep(1000);
    }
    gotoxy(2, 17);
    printf("%d개 맞았으며, %d개 틀렸고 %d개가 시간을 초과했습니다.\n", p1.correct
          ,p1.incorrect,p1.timeout);
    printf("수고하셨습니다.\n");
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}