#include <stdio.h>
#include <string.h>
#include <time.h>

int inyear() {
    int year = 0;
    int t = 0;
    while (1) {
        printf("year을 입력하세요. ");
        t = scanf("%d", &year);
        if (t == 1) {
            if (year < 2025) {
                printf("year은 2025이상으로 입력하세요.\n");
            } else {
                break;
            }
        } else {
            printf("year은 숫자로 입력하세요.\n");
            while (getchar() != '\n');
        }
    }
    return year;
}

int inmonth() {
    int month = 0;
    int t = 0;
    while (1) {
        printf("month을 입력하세요. ");
        t = scanf("%d", &month);
        if (t == 1) {
            if (month <= 0 || month > 12) {
                printf("month는 1에서 12까지의 수 입니다.\n");
            } else {
                break;
            }
        } else {
            printf("month는 숫자로 입력하세요.\n");
            while (getchar() != '\n');
        }
    }
    return month;
}

void dday() {
    printf("\n\n*현재 날짜로부터 D-Day 계산*\n");
    int t, yy, mm, dd = 0;
    time_t start, end;
    struct tm tme = {0};
    start = time(NULL);
    while (1) {
        printf("년도를 입력하세요. ");
        t = scanf("%d", &yy);
        if (t != 1) {
            printf("\n년도는 숫자로 입력하세요.\n");
            while(getchar() != '\n');
        } else {
            if (yy <= 0) {
                printf("\n년도는 양의 정수 입니다.\n");
            } else {
                break;
            }
        }
    }
    
    while (1) {
        printf("월을 입력하세요. ");
        t = scanf("%d", &mm);
        if (t != 1) {
            printf("\n월은 숫자로 입력하세요.\n");
            while(getchar() != '\n');
        } else {
            if (mm > 12 || mm <= 0) {
                printf("월은 1에서 12까지 입니다.\n");
            } else {
                break;
            }
        }
    }
    
    while (1) {
        printf("일을 입력하세요. ");
        t = scanf("%d", &dd);
        if (t != 1) {
            printf("\n일은 숫자로 입력하세요.\n");
            while(getchar() != '\n');
        } else {
            if (dd > 31 || dd <= 0) {
                printf("일은 1에서 31까지 입니다.\n");
            } else {
                if (yy % 4 == 0 && mm == 2 && dd > 30) {
                    printf("윤년의 2월은 29일까지입니다.\n");
                } else if (yy % 4 != 0 && mm == 2 && dd > 29) {
                    printf("평년의 2월은 28일까지입니다.\n");
                } else {
                    break;
                }
            }
        }
    }
    
    printf("입력한 날짜 : %d년 %d월 %d일\n", yy, mm, dd);
    tme.tm_year = yy - 1900;
    tme.tm_mon = mm - 1;
    tme.tm_mday = dd;
    end = mktime(&tme);
    double diff = difftime(end, start) / (60 * 60 * 24);
    if (diff <= 0) {
        diff = -diff;
        printf("D+%.0f일", diff);
    } else {
        printf("D-%.0f일", diff);
    }
}

int endday(int year, int month) {
    int eday = 0;
    if (month == 2) {
        if (year % 4 == 0) {
            eday = 29;
        } else if (year % 4 == 0 && year % 100 == 0) {
            eday = 28;
        } else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
            eday = 29;
        } else {
            eday = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        eday = 30;
    } else {
        eday = 31;
    }
    return eday;
}

void printday(int day, int start) {
    int cnt = start;
    for (int j = 0; j < start; j++) {
        printf("    ");
    }
    for (int i = 1; i <= day; i++) {
        if (cnt == 6) {
            printf(" %2d ", i);
            printf("\n");
            cnt = 0;
        } else {
            printf(" %2d ", i);
            cnt++;
        }
    }
}

int startw(int year, int month, int ws) {
    enum month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    int sd = 0;
    int dsum = ws;
    for (int i = 2025; i < year; i++) {
        for (int k = jan; k <= dec; k++) {
            dsum = dsum + endday(i, k);
        }
    }
    for (int j = 1; j < month; j++) {
        dsum = dsum + endday(year, j);
    }
    sd = dsum % 7;
    return sd;
}
void headprint(int year, int month) {
    printf("\n\t[%d년%2d월]\n", year, month);
    printf("  S   M   T   W   T   F   S\n");
    printf("----------------------------\n");
}

void main()
{
    enum day {sun, mon, tue, wed, thu, fri, sat};
    enum day d = wed;               // standard : 2025.1.1.Wed
    int y = inyear();               // input year
    int mth = inmonth();            // input month
    int eday = endday(y, mth);      // year and month's lastday
    int sd = startw(y, mth, d);     // start day of weekday set
    headprint(y, mth);
    printday(eday, sd);
    dday();
}