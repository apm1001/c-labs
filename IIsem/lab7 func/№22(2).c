#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//22
float f2(float e);
bool isValid2(float j){
    if(j<=0){
        printf("\nb ������ ���� ������ 0 �� ������� ���������");
        return false;
    }
    else return true;
}
bool isValid1(float p, float q){
    if((6*p-f2(q))==0){
        printf("\n������� �� ���� ����������!(6*x-f2(%g)=0)",q);
        return false;
    }
    else return true;
}
float f1(float x,float y,float z){

    return (8*x-log(y))/(6*x-f2(z));
}

float f2(float e){

    return (7-5*abs(e));
}
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));

    float a,b,c;
    int k;
M1: printf("������� ����� a,b,c:\n");
    printf("a = "); scanf("%f",&a);
    printf("b = "); scanf("%f",&b);
    printf("c = "); scanf("%f",&c);
    if(isValid2(b)&&isValid1(a,c)){
        printf("\nF2 = %g",f2(c));
        printf("\nF1 = %g",f1(a,b,c));
    }
    else{
        printf("\n���������� �����:\n");
        goto M1;
    }
M2:
    printf("\n������ ����������� �����?(1-��|2-��������� ���������)-->");
    scanf("%i",&k);
    switch(k){
    case 1: goto M1; break;
    case 2: break;
    default:printf("������������ ��������, ���������� �����!"); goto M2;
    }

}
