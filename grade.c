/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    float s = 0.0;
    while (1)
    {
        printf("시험 점수를 입력하세요.\n");
        scanf("%f", &s);
        
        if (s > 100.0 | s < 0.0) {
            printf("점수는 0부터 100까지의 수 입니다.\n");
        } else break;
    }
    
    float bs = 0.0;
    switch((int)(s / 10))
    {
        case 10: case 9:
            printf("A등급\n");
            bs = s * 0.1;
            printf("보너스 점수 : %.2f\n", bs);
            printf("보너스 점수를 합한 점수 : %.2f", s + bs);
            break;
        case 8:
            printf("B등급\n");
            bs = s * 0.05;
            printf("보너스 점수 : %.2f\n", bs);
            printf("보너스 점수를 합한 점수 : %.2f", s + bs);
            break;
        case 7:
            printf("C등급");
            break;
        case 6:
            printf("D등급");
            break;
        default:
            printf("F등급");
    }
}
