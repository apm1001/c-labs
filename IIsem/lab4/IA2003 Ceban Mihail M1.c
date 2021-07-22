#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
//16,685,684
main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    const int n = 4;
    float d[n][n],a[n][n],sum,sr,s=0;
    int i,j,k=0;

    printf("Массив D:\n");

    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            d[i][j] = abs(exp(i)-exp(j)) + (i+j)/2.0 +1;
            printf("%5.1f",d[i][j]);
        }
        printf("\n");
    }
    SetColor(2);
    printf("\nВывод ответа. Массив A(среднее арифметическое индексов соседей если сумма соседей больше):\n");
    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0){
                if(j==0){
                    sum = d[i+1][j]+d[i][j+1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i+j+1;
                        a[i][j] = sr/4;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else if(j==n-1){
                    sum = d[i+1][j]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i+j-1;
                        a[i][j] = sr/4;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else{
                    sum = d[i+1][j]+d[i][j+1]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i+j+1+i+j-1;
                        a[i][j] = sr/6;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
            }
            else if(i==n-1){
                if(j==0){
                    sum = d[i-1][j]+d[i][j+1];
                    if(d[i][j]<sum){
                        sr = i-1+j+i+j+1;
                        a[i][j] = sr/4;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else if(j==n-1){
                    sum = d[i-1][j]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i-1+j+i+j-1;
                        a[i][j] = sr/4;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else{
                    sum = d[i-1][j]+d[i][j+1]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i-1+j+i+j+1+i+j-1;
                        a[i][j] = sr/6;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
            }
            else{
                if(j==0){
                    sum = d[i+1][j]+d[i-1][j]+d[i][j+1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i-1+j+i+j+1;
                        a[i][j] = sr/6;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else if(j==n-1){
                    sum = d[i+1][j]+d[i-1][j]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i-1+j+i+j-1;
                        a[i][j] = sr/6;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
                else{
                    sum = d[i+1][j]+d[i-1][j]+d[i][j+1]+d[i][j-1];
                    if(d[i][j]<sum){
                        sr = i+1+j+i-1+j+i+j+1+i+j-1;
                        a[i][j] = sr/8;
                        s+=a[i][j]; k++;
                        SetColor(3);
                        printf("%5.1f",a[i][j]);
                    }
                    else {
                        a[i][j] = d[i][j];
                        SetColor(5);
                        printf("%5.1f",a[i][j]);
                    }
                }
            }

        }
        printf("\n");
    }
    printf("\nСумма замененных элементов = %.2f",s);
    printf("\nКоличество замененных элементов = %i",k);



}
