# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void qusort(int arr[], int first, int last) {
    // qusort(arry, startindex, lstindex)
    if (last <= first) {
        return;
    }
    
    int pidx = last;   // pivot = last element
    int lidx = first; 
    int ridx = last - 1; 
    int tmp = 0;
	
    while (lidx <= ridx) {
        while (arr[lidx] <= arr[pidx] && lidx < last) { 
            lidx++;
        }
        while (arr[ridx] >= arr[pidx] && ridx > first) { 
            ridx--;
        }
        if (lidx > ridx) {  
            tmp = arr[lidx];
            arr[lidx] = arr[pidx];
            arr[pidx] = tmp;
        } else { 
            tmp = arr[ridx];
            arr[ridx] = arr[lidx];
            arr[lidx] = tmp;
        }
    }
    qusort(arr, first, lidx - 1);
    qusort(arr, lidx + 1, last);
}

void main() {   
    
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
    }
    
    /*quick sort*/
    qusort(numarr, 0, 5);
   
    for (int k = 0; k < 6; k++) {
        printf("%d\n", numarr[k]);
    }
}