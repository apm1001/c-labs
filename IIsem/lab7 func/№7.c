#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//17
void f1(n){
    int i;
    f3(n);
    for(i=0;i<6-n;i++){
        printf("___");
    }
    printf("_");
    printf("\n");
}

void f2(){
    int i,j;
    for(j=5;j>0;j--){
        f1(6-j);
        f3(6-j);
        for(i=j+1;i>0;i--){
            printf("|  ");
            if(i==1){
                printf("\n");
            }
        }
        f4(6-j);

    }
}
void f3(n){
    int i;
    for(i=n;i>0;i--){
        printf("   ");
    }
}
void f4(n){
    int i;
    f3(n);
    for(i=0;i<6-n;i++){
        printf("---");
    }
    printf("-");
    printf("\n");
}
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));

    f2();

}
