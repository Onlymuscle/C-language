#include<stdio.h>

char arAlphabet[27];

void alphabet();

void main()
{
    int i=0, j;
    int count = 0;

    char input[100];

    alphabet();

    printf("문장을 입력해주세요:\n");
    scanf_s("%s", input,100);

     for (i; i < 26; i++) {
        for (j = 0; j < 100; j++) {
            if (arAlphabet[i] == input[j]) {
                count++;
            }
            else if (input[j] == NULL) {
                break;
            }
        }
            if(count!=0){
            printf("%c : %d\t", arAlphabet[i], count);
            count = 0;
            }
     }
}
void alphabet()
{
    int k,i;
    
    for (i = 0, k = 97; i < 26; i++) {
        arAlphabet[i] = k++;
    }
}