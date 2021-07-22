#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <workWithOMArray.h>
#include <color.h>
#include <iostream>
#define forI for(int i=0;i < n;i++)
#define forJ for(int j=0;j < n;j++)

int y(int y, int z, int x){

    return (x*x*x*y+x*x*z+1);
}

int minY(int u, int v){
    int i,minim=999999;

    for(i=0;i<=10;i+=2){
        minim = Min(minim,y(u,v,i));
    }
    return minim;
}
/*
Функция, которая получает указатель на двумерный массив и
координаты i,j пересечения строки и столбца, на пересечении
которых функция y имеет минимальное значение.
Фунцкия возвращает минимальное и среднее значение элементов этой строки,
а затем столбца.
*/
void maxAndSred(int **x,int n,int yi,int yj,int *maximI,int *maximJ,float *sredArI,float *sredArJ){
    int summaI=0,summaJ=0;

    *maximI = *maximJ = -999999;

    forI{
        *maximI = Max(*maximI,x[yi][i]);
        *maximJ = Max(*maximJ,x[i][yj]);
        summaI += x[yi][i];
        summaJ += x[i][yj];
    }

    *sredArI = (float)summaI/n;
    *sredArJ = (float)summaJ/n;
}

int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k,n;
    char ch;
    printf("\nВведите размерность матрицы N = ");
    scanf("%i",&n);
M2:
    printf("\nВыберите способ ввода массива:\n1 - с клавиатуры\n2 - случайно -->");
    scanf("%i",&k);
    int **a, **b;
    createDinMatr(a,n);
    createDinMatr(b,n);
    int ki[n],kj[n];
    char chA='A',chB='B';
    float SredArI,SredArJ;
    int maximI=-999999,maximJ=-999999;
    switch(k){
    case 1:
        printf("Массив А:\n");
        inputMatrKeyB(a,n,chA);
        printf("Массив B:\n");
        inputMatrKeyB(b,n,chB);
        break;
    case 2:
        inputMatrRand(a,n);
        inputMatrRand(b,n);
        break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M2;
    }
    printf("\nArray A:\n");
    outputMatr(a,n);
    printf("\nArray B:\n");
    outputMatr(b,n);
    forI{
        ki[i] = -1;
        kj[i] = -1;
    }
    printf("\nВывод ответа:\n");
    int minYValue=999999;
    SetColor(2);
    forI{
        forJ{
            minYValue = Min(minYValue,minY(a[i][j],b[i][j]));
        }
    }
    forI{
        forJ{
            if(minY(a[i][j],b[i][j])==minYValue){
                SetColor(3);
                printf("%4i",a[i][j]);
                SetColor(2);
                //запоминаю координаты нужных строк и столбцов
                ki[i] = i;
                kj[j] = j;
            }
            else{
                printf("%4i",a[i][j]);
            }
        }
        printf("      |   ");
        forJ{
            if(minY(a[i][j],b[i][j])==minYValue){
                SetColor(3);
                printf("%4i",b[i][j]);
                SetColor(2);
            }
            else{
                printf("%4i",b[i][j]);
            }
        }
        printf("\n");
    }

    forI{
        forJ{
            if((minY(a[i][j],b[i][j])==minYValue)&&(ki[i]!=-1||kj[j]!=-1)){
                SetColor(3);
                printf("\nВывод для массива A:");
                SetColor(2);
                maxAndSred(a,n,i,j,&maximI,&maximJ,&SredArI,&SredArJ);
                if(ki[i]!=-1){
                    printf("\nМаксимальный элемент %i-ой строки = %i",i,maximI);
                    printf("\nСреднее арифметическое %i-ой строки = %.2f",i,SredArI);
                }
                if(kj[j]!=-1){
                    printf("\nМаксимальный элемент %i-ого столбца = %i",j,maximJ);
                    printf("\nСреднее арифметическое %i-ого столбца = %.2f",j,SredArJ);
                }
                SetColor(4);
                printf("\nВывод для массива B:");
                SetColor(2);
                maxAndSred(b,n,i,j,&maximI,&maximJ,&SredArI,&SredArJ);
                if(ki[i]!=-1){
                    printf("\nМаксимальный элемент %i-ой строки = %i",i,maximI);
                    printf("\nСреднее арифметическое %i-ой строки = %.2f",i,SredArI);
                    ki[i] = -1;
                }
                if(kj[j]!=-1){
                    printf("\nМаксимальный элемент %i-ого столбца = %i",j,maximJ);
                    printf("\nСреднее арифметическое %i-ого столбца = %.2f",j,SredArJ);
                    kj[j] = -1;
                }
            }
        }
    }
    SetColor(15);
    deleteDinMatr(a,n);
    deleteDinMatr(b,n);
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
