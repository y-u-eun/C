/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    
    /*bubble sort*/
    int tmp = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
          if (numarr[i] < numarr[j]) {
            tmp = numarr[i];
            numarr[i] = numarr[j];
            numarr[j] = tmp;
        }
        tmp = 0;  
        }
    }
    
    for (int k = 0; k < 6; k++) {
        printf("%d\n", numarr[k]);
    }
    
}