#include <stdio.h>

int Fibo(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return Fibo(n - 1) + Fibo(n - 2);
    }
}

int input() {
    int num = 0, t = 0;
    while (1) {
        printf("출력할 숫자의 개수를 입력하세요. ");
        t = scanf("%d", &num);
        if (t != 1) {
            printf("\n숫자를 입력하세요.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    return num;
}
void printout(int n) {
    int sum = 0, cnto = 0, cnte = 0;
    for (int i = 0; i < n; i++) {
        int ans = Fibo(i);
        sum = sum + ans;
        printf("%d ", ans);
        if (ans % 2 == 1) {
            cnto++;
        } else {
            cnte++;
        }
    }
    printf("\n합 : %d", sum);
    printf("\n홀/짝: %d/%d", cnto, cnte);
}

void main() {
    int ipnum = input();
    printout(ipnum);
}