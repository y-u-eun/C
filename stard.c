#include <stdio.h>

int inputnum() {
    int n = 0, t = 0;
    while (1) {
        printf("홀수를 입력하세요. ");
        t = scanf("%d", &n);
        if (t != 1) {
            printf("\n숫자를 입력하세요.\n");
            while (getchar() != '\n');
        } else {
            if (n % 2 == 0) {
                printf("\n짝수입니다.\n");
                while (getchar() != '\n');
            } else {
                break;
            }
        }
    }
    
    return n;
}

void printd(int n) {
    int e = 1;
    int b = n / 2;
    for (int i = 0; i < n; i++) {
        for (int k = b; k > 0; k--) {
            printf(" ");
        }
        b--;
        for (int j = 1; j <= e; j++) {
            printf("*");
        }
        printf("\n");
        e+=2;
        if (e > n) {
            e = n - 2;
            break;
        }
    }
    b = 1;
    for (int i = 0; i < n; i++) {
        for (int k = b; k > 0; k--) {
            printf(" ");
        }
        b++;
        for (int j = e; j > 0; j--) {
            printf("*");
        }
        printf("\n");
        e-=2;
        if (e < 0) {
            break;
        }
    }
}

void main()
{
    int num = inputnum();
    printd(num);
}
