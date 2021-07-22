#include <stdio.h>
#include <color.h>
#include <gotoxy.h>
//6
void f1(){
    printf("__");
    printf("\n");
}

void f2(n){
    int i,j;
    for(i=0;i<2;i++){
        printf("|");
        gotoxy(3*n,2*n-1+i);
        printf("|");
        printf("\n");
    }
    gotoxy(3*n+1,2*n-1+1);

}


main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));
    printf(" ");
    int i;
    for(i=1;i<5;i++){
        f1();
        f2(i);

    }
    printf("\n");
    for(i=0;i<7;i++){
        printf("--");
    }

}
