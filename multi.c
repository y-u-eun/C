/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int abc = 0;
    int result = 0;
    
    while (1) {
        printf("세 자리 정수를 입력하세요.\n");
        scanf("%d", &abc);
        if (abc < 100 || abc > 999) {
            printf("세 자리 정수를 입력하세요.\n");
            scanf("%d", &abc);
         } else {
            break;
        }
    }
    
    int a, b, c;
    
    c = abc % 10;
    b = (abc / 10) % 10;
    a = abc / 100;
    result = a + b + c;
    
    printf("%d", result);
}
