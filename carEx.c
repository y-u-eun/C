#include <stdio.h>

void main() {
    
    enum car {SEDAN = 1, SUV, TRUCK, VAN};
    printf("*자동차의 종류*\n");
    for (int i = SEDAN; i <= VAN; i++) {
        switch (i) {
            case 1:
                printf("%d.SEDAN ", i);
                break;
            case 2:
                printf("%d.SUV ", i);
                break;
            case 3:
                printf("%d.TRUCK ", i);
                break;
            case 4:
                printf("%d.VAN\n", i);
                break;
        }
    }
    int num = 0, t = 0;
    
    while (1) {
        printf("\n출력할 차량의 번호를 입력하세요. ");
        t = scanf("%d", &num);
        if (t != 1) {
            printf("\n번호를 입력하세요.\n");
            while (getchar() != '\n');
        } else {
            if (num <=0 || num > 4) {
                printf("\n번호는 1에서 4까지 입니다.\n");
                while (getchar() != '\n');
            } else {
                break;
            }
        }
    }
    switch (num) {
        case SEDAN:
            printf("\n선택한 차량은 SEDAN입니다.");
            break;
         case SUV:
            printf("\n선택한 차량은 SUV입니다.");
            break;
         case TRUCK:
            printf("\n선택한 차량은 TRUCK입니다.");
            break;
         case VAN:
            printf("\n선택한 차량은 VAN입니다.");
            break;
    }
}