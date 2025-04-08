#include <stdio.h>

void main()
{
    printf("**1부터 N까지 출력**\n\n");
    
    int num = 0;
    while (1) {
        printf("1보다 큰 정수를 입력해주세요.");
        scanf("%d", &num);
        if (num <= 1) {
            printf("1보다 작거나 같습니다.\n");
        } else {
            break;
        }
    }
    
    int i = 1;
    while (i <= num) {
        printf("%d ", i);
        i++;
    }
}