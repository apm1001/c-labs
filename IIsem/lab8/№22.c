#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//22
bool isValid2(float j){
    if(j==0){
        printf("\nДеление на ноль невозможно!(s=0)");
        return false;
    }
    else return true;
}
bool isValid1(float j){
    if(5-abs(j)==0){
        printf("\nДеление на ноль невозможно!(5-|c|=0)");
        return false;
    }
    else return true;
}
float v(float a,float b,float c){

    return (2*a-b-sin(c))/(5-abs(c));
}

int maxDel(int x){
    int k=0,i;
    for(i=1;i<=x/2;i++){
        if(x%i==0){
            k++;
        }
    }
    return k;
}
int m(int o,int y){
    if(o>y){
        return o;
    }
    else return y;
}
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));

    int t,s,k;
M1: printf("Введите числа t и s:\n");
    printf("t = "); scanf("%i",&t);
    printf("s = "); scanf("%i",&s);
    if(isValid2(s)&&isValid1(s-t)){
        if(m(maxDel(t),maxDel(s))>3*s-9){
            printf("\nОтвет: %.2f",v(t,-2/s,4.17)+v(2.6,t,s-t));
        }
        else{
            printf("\nОтвет: %.2f",v(t-2/s,s*t,1.27)-v(4.5,s+t,s-t));
        }
    }
    else{
        printf("\nПопробуйте снова:\n");
        goto M1;
    }
M2:
    printf("\nХотите попробовать снова?(1-да|2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1: goto M1; break;
    case 2: break;
    default:printf("Недопустимое значение, попробуйте снова!"); goto M2;
    }

}
