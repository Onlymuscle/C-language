#include<stdio.h>
#include<stdbool.h>

extern int arleapyear[200]={1900};
int c;

void leapyear();
int leapyearcheck(void);

void main()
{
    static int i,year;

    int month, day;
    int b; 
    
        printf("dddd/mm/dd �������� ��¥�� �Է����ּ���\n");
        scanf_s("%4d%2d%2d", &year, &month, &day);
        c = year;

            leapyear();
            leapyearcheck();

        if (c == 1 ) {
            printf("%d �� %d �� %d ���� �����Դϴ�:\n", year, month, day);
        }
        else {
            printf("%d �� %d �� %d ���� ������ �ƴմϴ�:\n", year, month, day);
        }
}
void leapyear()
{
    static int i,j;

    for (i = 0, j = 0; i < sizeof(arleapyear)/sizeof(arleapyear[0]); i++) {
        arleapyear[i] = arleapyear[0] + j++;
    } 
}
int leapyearcheck(void)
{
    static int year;

    int i, j;
    static int d;
    j = c;

    for (i = 0; i < sizeof(arleapyear) / sizeof(arleapyear[0]); i++) {
        if ((arleapyear[i] % 4) == 0) {

            if ((arleapyear[i] % 100) == 0) {

                if ((arleapyear[i] % 400) == 0) {
                    c = 1;
                }
            }else {
                c = 1;
            }
        }
        else {
            c = 0;
        }
        if (j == arleapyear[i]) {
            return c;
            break;
        }
    }
}