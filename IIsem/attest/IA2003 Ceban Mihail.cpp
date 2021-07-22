#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "workWithOMArray.h"
#include <color.h>
#include <iostream>
#define forI for(int i=0;i < n;i++)
#define forJ for(int j=0;j < n;j++)

// в пункте 1 лучше вводить более маленькую матрицу
void f1(int x){
    int a, b, c;

    for(c = 0;c<=100;c++){
        for(b = 0;b<=c;b++){
            for(a = 0;a<=b;a++){
                if((a+b+c)>=x&&(a+b+c)%x==0&&x!=0){
                    printf("\na = %i   b = %i   c = %i",a,b,c);
                }
            }
        }
    }
}
void f2(int** x,int n,int* ii,int* jj,int* ii1,int* jj1,int* maxDif){

    forI{
        forJ{
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    if(x[i][j]-x[u][v]>(*maxDif)){
                        if(i==u&&j==v){
                            continue;
                        }
                        *ii = i;
                        *jj = j;
                        *ii1 = u;
                        *jj1 = v;
                        *maxDif = x[i][j] - x[u][v];
                    }
                }
            }

        }
    }
}

bool NextSet(int *c, int n, int m)
{
    int k = m;
    for (int i = k - 1; i >= 0; --i)
        if (c[i] < n - k + i )
        {
          ++c[i];
          for (int j = i + 1; j < k; ++j)
            c[j] = c[j - 1] + 1;
          return true;
        }
    return false;
}

bool isClose(int *c, int *b, int n, int m, int *maxim, int *point, int *nomer, bool print)
{
    int sum =0;
    for (int i = 0; i < m; i++){
        sum+=b[c[i]];
    }
    for (int i = 0; i < m; i++){
        if(b[c[i]]>=sum/(m-1)){
            return false;
        }
    }
    (*point)++;
    if(*point==*nomer){
        printf("\nНаибольшая последовательность близких чисел:\n");
        for (int i = 0; i < m; i++){
        printf("%4i",b[c[i]]);
        }
        return true;
    }
    if(print){
        for (int i = 0; i < m; i++){
            printf("%4i",b[c[i]]);
        }
        printf("\n");
        if(sum>(*maxim)){
            *maxim = sum;
            *nomer = *point;
        }
    }
    return false;


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
    int **a, *b, *c;
    int ii,jj,ii1,jj1,maxDif=-999999;
    int vectCount = 0,point=0,maxim=-999999,nomer=-1;
    bool isAnswer=false, print=true;
    createDinMatr(a,n);
    char chA='A';
    switch(k){
    case 1:
        printf("Массив А:\n");
        inputMatrKeyB(a,n,chA);
        break;
    case 2:
        inputMatrRand(a,n);
        break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M2;
    }
    printf("\nArray A:\n");
    outputMatr(a,n);

M1:
    printf("\nВыберите случай:\n1)\n2)\n3)\n-->");
    ch = getche();
    switch(ch){
    case '1':
        printf("\nВывод ответа:\n");

        forI{
            forJ{
                printf("\nДля числа %i:\n",a[i][j]);
                f1(a[i][j]);
            }
        }


        break;

    case '2':


        f2(a,n,&ii,&jj,&ii1,&jj1,&maxDif);

        printf("\nВывод ответа:\n");

        SetColor(2);
        forI{
            forJ{
                if(i==ii&&j==jj){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(2);
                }
                else if(i==ii1&&j==jj1){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(2);
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
        break;
    case '3':

        printf("\nСоставим вектор из матрицы:\n");
        createDinVect(b,n*n);
        forI{
            forJ{
                b[vectCount++] = a[i][j];
            }
        }
        n*=n;
        createDinVect(c,n);
        forI{
            c[i] = i;
            printf("%5i",c[i]);
        }
        SetColor(2);
        printf("\n");
        forI{
            printf("%5i",b[i]);
        }
        SetColor(15);

        printf("\nВывод близких сочетаний:\n");

        for(int m=2;m<n;m++){
            isClose(c, b, n, m, &maxim, &point, &nomer,print);
            while (NextSet(c, n, m))
                isClose(c,b,n,m,&maxim,&point, &nomer,print);
            forI{
                c[i] = i;
            }
        }
        print = false;
        point = 0;
        for(int m=2;m<n;m++){
            if(isClose(c, b, n, m, &maxim, &point, &nomer,print)){
                isAnswer = true;
                break;
            }
            while (NextSet(c, n, m)){
                if(isClose(c,b,n,m,&maxim,&point, &nomer,print)){
                    isAnswer = true;
                    break;
                }
            }
            if(isAnswer){
                break;
            }
            forI{
                c[i] = i;
            }
        }
        if(!isAnswer){
            printf("\nЗдесь нет последовательностей близких чисел!!!");
        }
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M1;
    }

    deleteDinMatr(a,n);
    deleteDinVect(b);
    deleteDinVect(c);
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
