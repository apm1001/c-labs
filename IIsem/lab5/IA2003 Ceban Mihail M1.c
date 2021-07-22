#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//23
main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));
    int k,n;
    char ch;
    printf("Введите размерность матрицы N = ");
    scanf("%i",&n);
    int a[n][n],i,j;
    bool ba,bb;
M1:
    printf("\nВыберите случай:\na)Найти самый маленький полож эл-т каждой строки и поменять местами с эл-ом на глав диаг, большим чем максимум эл-в строки на которой он расположен\nb)Найти столбец с самой маленькой суммой эл-ов, которые предшествуют первому отриц-му нах-му в столбце с отриц-м эл-ом на клавной диаг. Если такого отриц-го нет, выч-ть сумму последних 4 полож-х эл-ов столбца\n-->");
    ch = getche();
    ba=bb=false;
    switch(ch){
    case 'a':
        ba=true;
        break;
    case 'b':
        bb=true;
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M1;
    }
M2:
    printf("\n1)Массив вводим с клавиатуры.\n2)Массив генерируем случайно\n-->");
    ch = getche();
    printf("\n");
    switch(ch){
    case '1':
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("A[%i,%i] = ",i,j);
                scanf("%i",&a[i][j]);
            }
        }
        break;
    case '2':
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j] = (rand()%100)-50;
            }
        }
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M2;
    }
    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                printf("%4i",a[i][j]);
        }
        printf("\n");
    }
    SetColor(2);
    int min=99999,max=-99999,c,j1=-1,nn=n/2;
    bool neg=false;
    int sum[n],sum_el=0,sum_st=99999,i1;
    if(ba){
        printf("Выполнение условия a):\n");
        SetColor(5);
        for(i=0;i<n;i++){
            min = 99999;
            for(k=0;k<n;k++){
                if((i==nn)&&(max<a[i][k])){
                    max = a[i][k];
                    j1 = k;
                }
                if((min>a[i][k])&&(a[i][k]>0)){
                    min = a[i][k];
                }
            }
            if(i==nn){
                    c = a[nn][nn];
                    a[nn][nn] = max;
                    a[nn][j1] = c;
            }
            for(j=0;j<n;j++){
                if(a[i][j]==min){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if((i==nn&&j==nn)||(i==nn&&j==j1)){
                    SetColor(4);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
    }
    else{
        printf("Выполнение условия b):\n");
        SetColor(5);
        for(i=0;i<n;i++){
            sum[i]=0;
        }
        for(i=0;i<n;i++){
            neg=false;
            if(a[i][i]<0){
                neg = true;
            }
            if(neg){
                sum_el = 0;
                for(j=0;j<i;j++){
                    if(a[j][i]>0){
                        sum_el+=a[j][i];
                    }
                    else break;
                }
                if(sum_st>sum_el){
                    sum_st = sum_el;
                    i1=i;
                }
            }
            else{
                for(j=n-1,k=0;j>=0,k<5;k++,j--){
                    sum[i]+=a[j][i];
                }
            }
        }
        printf("\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j==i1){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
        SetColor(2);
        printf("\n\n");
        for(i=0;i<n;i++){
            if(sum[i]!=0){
                printf("%4i",sum[i]);
            }
            else{
                printf("    ");
            }
        }
    }
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto M1;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
