# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void main()
{   
    int numarr[6];
    for (int i = 0; i < 6; i++) {
        srand(time(NULL));
        int num = (int)(rand() % 45) + 1;
        numarr[i] = num;
        sleep(1);
        
        for (int j = 0; j < i; j++) {
            if (numarr[i] == numarr[j]) {
                i--;
            }
        }
        /*printf("%d\n", num);*/
    }
    
    /*insertion sort*/
    int tmp = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = i; j > 0; j--) {
          if (numarr[j - 1] > numarr[j]) {
              tmp = numarr[j - 1];
              numarr[j - 1] = numarr[j];
              numarr[j] = tmp;
          }
        }
        tmp = 0;
    }
    
    for (int k = 0; k < 6; k++) {
        printf("%d\n", numarr[k]);
    }
}

