/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int result = 0;
    
    while(1) {
        printf("숫자를 3개 입력하세요.\n");
        scanf("%d %d %d", &a, &b, &c);
        
        if (c == 0) {
        printf("c값에 0을 입력할 수 없습니다.\n");
        } else break;
    }
    
    result = (a + b) * c - (a - b) / c;
    printf("%d", result);

    return 0;
}