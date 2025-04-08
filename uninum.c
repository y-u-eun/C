#include <stdio.h>

void main()
{
    int m = 0;
    int n = 0;
    printf("M부터 N까지의 숫자 중 규칙을 만족하는 숫자 출력\n");
    while (1) {
        printf("M의 값을 입력하세요.");
        scanf("%d", &m);
        if (m < 0) {
            printf("M은 0이상의 수로 입력하세요.\n");
        } else {
            break;
        }
    }
    
    while (1) {
        printf("N의 값을 입력하세요.");
        scanf("%d", &n);
        if (n < m) {
            printf("N은 M보다 큰 수로 입력하세요.\n");
        } else {
            break;
        }
    }
    
    for (int j = m; j < n + 1; j++) {
        int tf = 0;
        int tmp = j;
        while (tmp > 0) {
            if (tmp % 10 == 7) {
                tf = 1;
                break;
            } else {
                tmp = tmp / 10;
            }
        }
        
        if (j % 7 == 0 || tf == 1) {
            continue;
        } else if (j % 5 == 0) {
            printf(" %d", j);
            break;
        } else {
            printf(" %d", j);
        }
    }
}
