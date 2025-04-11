#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define TRUE 1
// strcpy()와 strlen() 함수를 사용하기 위해 <string.h> 사용
// malloc()과 free() 함수를 사용하기 위해 <stdlib.h> 사용

struct student {
        char *name;
        int age;
        char sex;
        char *hob;
    };

void stprint(struct student *p) {
    // 구조체 배열의 시작 주소를 전달 받고, scanf()로 입력된 값을
    // 구조체 배열에 저장해서 구조체 배열의 값을 누적으로 출력하는 함수 선언

    struct student *pp = p;
    // 구조체 배열을 처음부터 누적 출력하기 위해 for문에서 사용할 포인터 변수를 선언
    p = p + 3;
    // 구조체 배열 s에 이미 3개의 데이터가 있으므로
    // 그 다음 주소부터 입력값을 저장할 수 있도록 p에 3을 더해준다.
    while (TRUE) {
        char tmp[100];  // 임시로 문자배열을 할당할 변수 선언
        printf("\n이름을 입력하세요. ");
        scanf("%s", tmp);
        p->name = malloc(strlen(tmp) + 1);  // 메모리(공간) 할당
        // malloc()은 주소를 반환
        // strlen()은 NULL 전까지 문자열의 길이를 불러옴
        // strlen(tmp) + 1 을 하면 "문자열\n"이 된다.
        strcpy(p->name, tmp);
        // strcpy()를 이용해 할당한 공간에 문자열을 대입
        
        printf("\n나이를 입력하세요. ");
        scanf("%d", &p->age);
        
        while (TRUE) {
            printf("\n성별을 입력하세요(M/F). ");
            getchar();
            scanf("%c", &p->sex);
            if (p->sex == 'M' || p->sex == 'F') {
                break;
            } else {
                printf("\n성별은 'M' 또는 'F'로 입력해주세요.\n");
            }
        }
        // 나이와 성별은 포인터변수로 선언하지 않았으므로 malloc()을 이용해 공간을
        // 할당하지 않고 주소값을 이용해 바로 저장할 수 있음.
        
        printf("\n취미를 입력하세요. ");
        scanf("%s", tmp);
        p->hob = malloc(strlen(tmp) + 1);
        strcpy(p->hob, tmp);
        
        p++;    // p가 다음 주소의 값을 갖도록 값을 증가 시켜준다.
        
        printf("\n===학생정보시스템===\n");
        for (struct student *p2 = pp; p2 < p; p2++) {
            printf("%d. %-s %-d %-c %-s\n", p2 - pp + 1, p2->name, p2->age, p2->sex, p2->hob);
            // p는 현재까지 입력된 값의 주소
            // p2는 구조체배열 s의 시작 주소부터 p까지 1씩 증가
            // 출력할 값의 주소(=p2)에서 구조체 배열 s의 주소(=s)를 빼줘야
            // 출력할 값의 인덱스를 알 수 있음. 인덱스는 0부터 시작하므로 1을 더해서
            // 1부터 출력할 수 있도록 설정
        }
    }
    
    // 구조체 포인터에 malloc()으로 메모리를 할당해서 사용한 후
    // 메모리 누수를 방지하기 위해 free()를 이용해 할당한 메모리를 해제해 줘야 함.
    for (struct student *p3 = pp; p3 <= p; p3++) {
        free(p3->name);
        free(p3->hob);
    }
}

void main() {
    
    printf("===학생정보시스템===\n");
    struct student s [MAX] = {
        {"hong", 30, 'M', "soccer"},
        {"kim", 25, 'M', "music"},
        {"park", 20, 'F', "movie"}
    };
    
    for (int k = 0; k <= 2; k++) {
            printf("%d. %-s %-d %-c %-s\n", k + 1, s[k].name, s[k].age, s[k].sex, s[k].hob);
        }
    
    stprint(&s);    // stprint()에 구조체 배열 s의 주소를 전달
    
}
