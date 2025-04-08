#include <stdio.h>
// 이중 for문을 활용해서 202001-202504까지 출력
// 202302에서 202305 제외

void main()
{
    int y[6] = {2020, 2021, 2022, 2023, 2024, 2025};
    int m[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 12; j++) {
            if (y[i] == 2023 && (m[j] >= 2 && m[j] <= 5)) {
                continue;
            } else if (y[i] == 2025 && (m[j] >= 5 && m[j] <= 12)) {
                continue;
            }
            printf("%d%02d\n", y[i], m[j]);
        }
    }
}
