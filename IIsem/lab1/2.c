#include <stdio.h>
#include "color.h"
#include <time.h>
#include <stdbool.h>
//14 var
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int n = 50;
    int a[n],i,max,min=0,sum;

    ClearConsoleToColors(2,7);
    printf("������ �:\n");

    for(i = 0;i<n;i++){
        printf("%4i",i);
    }
        SetColor(5);
    printf("\n");
    for(i = 0;i<n;i++){
        a[i] = rand()%100-50;
        printf("%4i",a[i]);
    }
    SetColor(2);
    bool b = false;
    int i1,i2;
    max = -999999;
    for(i=1;i<n-1;i++){
        if((a[i-1]%2 == 1)&&(a[i+1]%2 == 1)&&(a[i-1]%3 == 0)&&(a[i+1]%3 == 0)){
            sum = a[i-1]+a[i+1];
            if(max<sum) max = sum;
            b = true;
            i1 = i-1;
            i2 = i+1;
        }
    }
    if(b){
        printf("\nmax[%i,%i](�����  �������� �����-� ��������� �� 3 ���������) = %i",i1,i2,max);
    }
    //min(�������������)

    for(i = 0;i<n;i++){
        if((a[i]<0)&&(a[i]<min))
            min = a[i];
    }
    printf("\nmin(�������������) = %i\n",min);
    //���� ��� ������������ �������� �������� ��������� ������ ��������� �� [n,m],
    //����� ������� �������������� ��������� ������������� [n,m], ����� � ����� ����������� �� ���� ������.
    int n1,m;
    float sred,j;
    printf("\n������� ������� [n,m]:\n");
    printf("n = "); scanf("%i",&n1);
    printf("m = "); scanf("%i",&m);

    int k;
    if(m%2 == 0){
        k = m;
    }
    else k = m-1;
    j = sum = 0;
    if(max == k){
        for(i=n1;i<=m;i++){
            sum+=i;
            j++;
        }
        sred = sum/j;
        printf("������� �������������� ��������� ������������� [n,m] = %g",sred);

    }
    else{
        int min1=999999;
        for(i=0;i<n;i++){
            if((a[i]%2 == 0)&&(min1>a[i])){
                min1 = a[i];
            }
        }
        printf("\n����������� �� ���� ������ = %i",min1);
    }





}
