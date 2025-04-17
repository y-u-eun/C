#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lotto {
	int one, two, three, four, five, six, bonus;
	int min, max, sum;
	float ave;
};

struct lotto lt[567];

void maxmin(struct lotto *lp) {
    int nums[7] = {lp->one, lp->two, lp->three, lp->four, lp->five, lp->six, lp->bonus};
    int min = 45;
    int max = 1;

    for (int i = 0; i < 7; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    lp->min = min;
    lp->max = max;
}

void sumave(struct lotto *lp) {
	lp->sum = lp->one + lp->two + lp->three + lp->four + lp->five + lp->six + lp->bonus;
	lp->ave = lp->sum / 7.0;
}

int main(void) 
{
	FILE *file = fopen("C:/lotto.csv", "r");
	
	char line[1024];
	
	fgets(line, 100, file);
	
	char *ptr = strtok(line, ",");
	
	while (ptr != NULL) {
		printf(" %s", ptr);
		ptr = strtok(NULL, ",");
	}
	
	int i = 0;
	while (fgets(line, 100, file)) {
		char *t = strtok(line, ",");
		
		lt[i].one = atoi(t);
		t = strtok(NULL, ",");
		lt[i].two = atoi(t);
		t = strtok(NULL, ",");
		lt[i].three = atoi(t);
		t = strtok(NULL, ",");
		lt[i].four = atoi(t);
		t = strtok(NULL, ",");
		lt[i].five = atoi(t);
		t = strtok(NULL, ",");
		lt[i].six = atoi(t);
		t = strtok(NULL, ",");
		lt[i].bonus = atoi(t);
		//printf("%d %d %d %d %d %d %d\n", lt[i].one, lt[i].two, lt[i].three, lt[i].four, lt[i].five, lt[i].six, lt[i].bonus);
		i++;
	}
	
	int tsum = 0, tsave = 0;
	for (int i = 0; i < 567; i++) {
		sumave(&lt[i]);
		maxmin(&lt[i]);
		tsum = tsum + lt[i].sum;
		tsave = tsum / 567.0;
	}
    
    int tsmin = 315, tsmax = 7;
    for (int i = 0; i < 567; i++) {
        if (lt[i].sum > tsmax) {
        	tsmax = lt[i].sum;
		}
		if (lt[i].sum < tsmin) {
			tsmin = lt[i].sum;
		}
    }
    
	printf("Total Sum -> Min : %d , Max : %d , Ave : %d\n", tsmin, tsmax, tsave);
	for (int i = 0; i < 567; i++) {
		printf("%d %d %d %d %d %d %d -> Sum : %d , Min : %d , Max : %d , Ave : %.2f\n", lt[i].one, lt[i].two, lt[i].three, lt[i].four, lt[i].five, lt[i].six, lt[i].bonus, lt[i].sum, lt[i].min, lt[i].max, lt[i].ave);
	}
	
	fclose(file);
	
	return 0;
}