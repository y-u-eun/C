/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    int a = 0;
    
    while(1) {
        printf("0에서 999까지의 숫자 중 하나를 입력하세요.\n");
        scanf("%d", &a);
    
        if (a >= 0 && a <= 999) {
            break;
         }
    }
    
    if (a < 100 && a >= 10) {
        if (a % 3 == 0 && a % 2 == 1) {
            printf("특별한 숫자 입니다.\n");
        } else if (((a % 10) + (a / 10)) % 7 == 0) {
            printf("특별한 숫자 입니다.\n");
        } else if ((a % 10) < (a / 10)) {
            printf("특별한 숫자 입니다.\n");
        } else {
            printf("특별한 숫자가 아닙니다.\n");
        }
    } else if (a >= 100 && a <=999) {
        if (a % 3 == 0 && a % 2 == 1) {
            printf("특별한 숫자 입니다.\n");
        } else if (((a % 10) + (a / 100) + ((a / 10) % 10)) % 7 == 0) {
            printf("특별한 숫자 입니다.\n");
        } else if ((a % 10) < (a / 100)) {
            printf("특별한 숫자 입니다.\n");
        } else {
            printf("특별한 숫자가 아닙니다.\n");
        }
    } else {
        if (a % 3 == 0 && a % 2 == 1) {
            printf("특별한 숫자 입니다.\n");
        } else if (a % 7 == 0) {
            printf("특별한 숫자 입니다.\n");
        } else {
            printf("특별한 숫자가 아닙니다.\n");
        }
    }
    
}