#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define TRUE 1

struct student_s {
        char *name;
        int age;
        char *gender;
        union student_u {
            char *hobby;
            char *etc;
        } u;
    };

void stprint(struct student_s *p) {
    
    struct student_s *pp = p;
    p = p + 3;
    
    while (TRUE) {
        char tmp[MAX];
        printf("\n이름을 입력하세요. ");
        scanf("%s", tmp);
        p->name = malloc(strlen(tmp) + 1);
        strcpy(p->name, tmp);
        
        while (TRUE) {
            printf("\n나이를 입력하세요. ");
            scanf("%d", &p->age);
            if (p->age <= 0) {
                printf("나이는 양의 정수입니다. 나이를 다시 입력하세요.\n");
            } else {
                break;
            }
        }
        
        while (TRUE) {
            printf("\n성별을 입력하세요(M/F). ");
            scanf("%s", tmp);
            if (strcmp(tmp, "M") == 0 || strcmp(tmp, "m") == 0 || strcmp(tmp, "male") == 0) {
                strcpy(tmp, "M");
                break;
            } else if (strcmp(tmp, "F") == 0 || strcmp(tmp, "f") == 0 || strcmp(tmp, "female") == 0) {
                strcpy(tmp, "F");
                break;
            } else {
                printf("\n성별은 'M/F' 또는 'm/f' 또는 'male/female'로 입력해주세요.\n");
            }
        }
        p->gender = malloc(strlen(tmp) + 1);
        strcpy(p->gender, tmp);
        
        printf("\n취미 또는 기타사항을 입력하세요(둘 중 하나만 입력 가능).\n입력사항이 없는 경우 'N/n' 또는 'NO/no'으로 입력");
        printf("\n취미 : ");
        scanf("%s", tmp);
        if (strcmp(tmp, "N") == 0 || strcmp(tmp, "NO") == 0 || strcmp(tmp, "n") == 0 || strcmp(tmp, "no") == 0) {
            printf("\n기타사항 : ");
            scanf("%s", tmp);
            if (strcmp(tmp, "N") == 0 || strcmp(tmp, "NO") == 0 || strcmp(tmp, "n") == 0 || strcmp(tmp, "no") == 0) {
                strcpy(tmp, " ");
            } else {
                p->u.etc = malloc(strlen(tmp) + 1);
                strcpy(p->u.etc, tmp);
            }
        } else {
            p->u.hobby = malloc(strlen(tmp) + 1);
            strcpy(p->u.hobby, tmp);
        }
        
        p++;
        
        printf("\n===학생정보시스템===\n");
        for (struct student_s *p2 = pp; p2 < p; p2++) {
            if (p2->u.hobby == NULL && p2->u.etc == NULL) {
                printf("%d. %-s %-d %-s\n", p2 - pp + 1, p2->name, p2->age, p2->gender);
            } else {
                printf("%d. %-s %-d %-s %-s\n", p2 - pp + 1, p2->name, p2->age, p2->gender, p2->u);
            }
        }
    }
    
    for (struct student_s *p3 = pp; p3 < p; p3++) {
        free(p3->name);
        free(p3->gender);
        free(p3->u.hobby);
        free(p3->u.etc);
    }
}

struct student_s s[MAX] = {
        {"hong", 30, "M", "soccer"},
        {"kim", 25, "M", "music"},
        {"park", 20, "F", "movie"}
};
    
void main() {

    printf("===학생정보시스템===\n");
    
    for (int k = 0; k <= 2; k++) {
            printf("%d. %-s %-d %-s %-s\n", k + 1, s[k].name, s[k].age, s[k].gender, s[k].u);
    }
    
    stprint(&s);
}