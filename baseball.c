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

		random[0] = random[3] / 100; // ù°�ڸ�
		random[1] = random[3] / 10 - random[0] * 10; //��°�ڸ�
		random[2] = random[3] % 10; //��°�ڸ�

		if (random[0] != random[1] && random[0] != random[2] && random[1] != random[2]) {
			break;
		}
	}
	printf("���̽� �� ���� ���� ���ڸ��� ���� �ٸ� ���� �Է��ϼ���.\n");

	for (turn = 0; turn < 9 || strike < 3; turn++) {

		printf("%d ȸ�� �õ�\n", turn);

		scanf_s("%d", &input[3]);

		input[0] = input[3] / 100; // ù°�ڸ�
		input[1] = input[3] / 10 - input[0] * 10; //��°�ڸ�
		input[2] = input[3] % 10; //��°�ڸ�

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

		printf("%d ��Ʈ����ũ %d �� \n", strike, ball);

		if (strike == 3) {
			printf("������� �¸� �ٽ� �Ͻðڽ��ϱ�\n");
			printf("y������ �ٽý��� n������ ����\n");
			goto b;
		}
		if (turn >= 10) {
			printf("���ӿ��� ������ %d%d%d �Դϴ�", random[0], random[1], random[2]);
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
				printf("������ �����մϴ�\n");
				exit(0);

			default:
				printf("y�� n�� �Ѱ��� �����ּ���\n");

			}
		}
	}
}