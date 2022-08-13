#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

void main()
{
	int random[4], input[4], turn, strike = 0, ball = 0;
	int i, j;
	char ch;

a:
	for (;;) {

		ch = 0;
		random[3] = 0;

		system("cls");

		srand(time(NULL));
		random[3] = (rand() % 900) + 99;

		random[0] = random[3] / 100; // 첫째자리
		random[1] = random[3] / 10 - random[0] * 10; //둘째자리
		random[2] = random[3] % 10; //셋째자리

		if (random[0] != random[1] && random[0] != random[2] && random[1] != random[2]) {
			break;
		}
	}
	printf("베이스 볼 게임 시작 세자리의 서로 다른 수를 입력하세요.\n");

	for (turn = 0; turn < 9 || strike < 3; turn++) {

		printf("%d 회차 시도\n", turn);

		scanf_s("%d", &input[3]);

		input[0] = input[3] / 100; // 첫째자리
		input[1] = input[3] / 10 - input[0] * 10; //둘째자리
		input[2] = input[3] % 10; //셋째자리

		strike = 0;
		ball = 0;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (random[i] == input[j])
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
			}
		}

		printf("%d 스트라이크 %d 볼 \n", strike, ball);

		if (strike == 3) {
			printf("사용자의 승리 다시 하시겠습니까\n");
			printf("y누르면 다시시작 n누르면 종료\n");
			goto b;
		}
		if (turn >= 10) {
			printf("게임오버 정답은 %d%d%d 입니다", random[0], random[1], random[2]);
			goto b;
		}
		else {
			continue;
		}
		b:
		if (ch = _getch()) {
			switch (ch) {

			case 'y':
				goto a;
				turn = 0;
				break;

			case 'n':
				printf("게임을 종료합니다\n");
				exit(0);

			default:
				printf("y와 n중 한개만 눌러주세요\n");

			}
		}
	}
}