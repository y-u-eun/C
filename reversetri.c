#include <stdio.h>
// 역 직각 삼각형 출력

void main() {
    
    printf("**역 직각 삼각형 출력**\n\n");
    
    int n = 0;
    while (1) {
        printf("1이상의 정수를 입력하세요.");
        scanf("%d", &n);
        if (n <= 0) {
            printf("0보다 작거나 같습니다.\n");
        } else {
            break;
        }
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("* ");
        }
        printf("\n");
    }
}