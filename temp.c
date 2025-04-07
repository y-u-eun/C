/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void main()
{
    float t = 0.0;
    printf("현재 온도를 입력하세요. ");
    scanf("%f", &t);
    int num = 0;
    
    if (t >= 30.0) {
        num = 1;
    } else if (t >= 25.0 &&  t < 30.0) {
        num = 2;
    } else if (t >= 15.0 &&  t < 25.0) {
        num = 3;
    } else if (t >= 5.0 &&  t < 15.0) {
        num = 4;
    } else if (t >= 0.0 &&  t < 5.0) {
        num = 5;
    } else {
        num = 6;
    }
    
    switch(num)
    {
        case 1 :
            printf("너무 더워요! 반팔과 반바지를 입으세요.");
            break;
        case 2 :
            printf("따뜻한 날씨입니다! 가벼운 옷을 입으세요.");
            break;
        case 3 :
            printf("선선한 날씨입니다! 가벼운 겉옷을 챙기세요.");
            break;
        case 4 :
            printf("조금 쌀쌀합니다! 따듯한 옷을 입으세요.");
            break;
        case 5 :
            printf("매우 춥습니다! 두꺼운 외투를 꼭 입으세요.");
            break;
        default :
            printf("한파 경고! 패딩과 장갑, 모자를 착용하세요!");
    }
    
}