#include <stdio.h>

void main()
{
    union values {
        int intVal;
        float floatVal;
        char charVal[100];
    } v;
    
    printf("\n정수를 입력하세요. ");
    scanf("%d", &v.intVal);
    printf("입력한 값 : %d\t주소값 : %d", v.intVal, &v.intVal);
    printf("\n실수를 입력하세요. ");
    scanf("%f", &v.floatVal);
    printf("입력한 값 : %f\t주소값 : %d", v.floatVal, &v.floatVal);
    printf("\n문자를 입력하세요. ");
    scanf("%s", &v.charVal);
    printf("입력한 값 : %s\t주소값 : %d", v.charVal, &v.charVal);
    
    printf("\n\n마지막으로 저장된 값 : %d\t주소값 : %d", v.intVal, &v.intVal);
    printf("\n마지막으로 저장된 값 : %f\t주소값 : %d", v.floatVal, &v.floatVal);
    printf("\n마지막으로 저장된 값 : %s\t주소값 : %d", v.charVal, &v.charVal);
};

