#include <stdio.h>
#include "color.h"
#include <time.h>
//14 var
main(){
    srand(time(NULL));
    const int n = 100;
    int a[100],i,j;

    printf("Array A:\n");
    ClearConsoleToColors(2,7);
    for(i = 0;i<100;i++){
        a[i] = rand()%100;
        printf("%3i",a[i]);
    }
}
