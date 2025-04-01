#include <stdio.h>
#include <stdlib.h>

int *find_overlap(int interval1[], int interval2[]){
    static int overlap[2];
    int max,min;

    if(interval1[0] > interval2[0])
         max= interval1[0];
    else max= interval2[0];

    if (interval1[1] < interval2[1])
         min= interval1[1];
    else min= interval2[1];

    if (max <= min){
        overlap[0]= max;
        overlap[1]= min;
        return overlap;
    }

    return NULL;
}//bi nemalo potreba od max, min i overlap ako moze edna od nizite da se modificira.

int main(){
    int interval1[]= {1000, 1200};
    int interval2[]= {1130, 1330};
    int interval3[]= {1315, 1400};
    int interval4[]= {1030, 1230};

    int *rez= find_overlap(interval1, interval2);
    if(rez)
        printf("[%d, %d]\n", rez[0], rez[1]);
     else
        printf("is None\n");

    rez= find_overlap(interval3, interval4);
    if(rez)
        printf("[%d, %d]\n", rez[0], rez[1]);
     else
        printf("is None\n");

    return 0;
}
