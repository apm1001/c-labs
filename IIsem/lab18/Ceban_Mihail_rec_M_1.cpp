#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
void inputKey(int **x,int n,int i,int j){
    if (i<n){
        if(j<n){
            printf("a[%i,%i] = ",i,j);
            scanf("%i",&x[i][j]);
            inputKey(x,n,i,j+1);
        }
        else{
            inputKey(x,n,i+1,0);
        }
    }
}
void inputRand(int **x,int n, int i,int j){
    if (i<n){
        if(j<n){
            x[i][j] = rand()%50-10;
            inputRand(x,n,i,j+1);
        }
        else{
            inputRand(x,n,i+1,0);
        }
    }
}
void out(int **x,int n, int i,int j){
    if (i<n){
        if(j<n){
            printf("%5i",x[i][j]);
            out(x,n,i,j+1);
        }
        else{
            printf("\n");
            out(x,n,i+1,0);
        }
    }
}
int Min(int o, int y){
    if(o>y){
        return y;
    }
    else{
        return o;
    }
}
int Max(int o, int y){
    if(o>y){
        return o;
    }
    else{
        return y;
    }
}/*
int minim(int *x,int n, int i, int minPoint){
    if(i<n-1){
        if(x[i]>0){
            minPoint = Min(x[i],minim(x,n,i+1,minPoint));
        }
        else{
            minim(x,n,i+1,x[i+1]);
        }
    }
    else{
        return minPoint;
    }
}*/
int minim(int *x,int n, int i,int minI, int minPoint){
    if(i==n){
        return minI;
    }
    if(minPoint>x[i]&&x[i]>=0){
        minPoint = x[i];
        minI = i;
    }
    i++;
    return minim(x,n,i,minI,minPoint);
}
int maxim(int *x,int n, int i,int maxI, int maxPoint){
    if(i==n){
        return maxI;
    }
    if(maxPoint<x[i]){
        maxPoint = x[i];
        maxI = i;
    }
    i++;
    return maxim(x,n,i,maxI,maxPoint);
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k, n=4,**a,*minPoints,i=0,m,p;
    bool b;
    printf("Type dimension of array N = ");
    scanf("%i",&n);
    a = new int *[n];
    for(int i=0;i<n;i++){
        a[i] = new int [n];
    }
    minPoints = new int [n];
    printf("Input with keyboard or random?(1 | 2)\n-->");
    scanf("%i",&k);
    if(k==1){
        inputKey(a,n,0,0);
    }
    else{
        inputRand(a,n,0,0);
    }
    printf("Array A:\n");
    out(a,n,0,0);

    for(int i=0;i<n;i++){
        minPoints[i] = minim(a[i],n,0,0,999999);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%4i",minPoints[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%6i",maxim(a[i],n,1,0,a[i][0]));
    }
    printf("\nAnswer:\n");
    SetColor(2);
    for(int i=0;i<n;i++){
        b = false;
        if(maxim(a[i],n,1,0,a[i][0])==i){
            p = a[i][maxim(a[i],n,1,0,a[i][0])];
            a[i][maxim(a[i],n,1,0,a[i][0])] = a[i][minPoints[i]];
            a[i][minPoints[i]] = p;
            b = true;
        }
        for(int j=0;j<n;j++){
            if((j==minPoints[i]||j==i)&&(b)){
                SetColor(3);
                printf("%5i",a[i][j]);
                SetColor(2);
            }
            else{
                printf("%5i",a[i][j]);
            }
        }
        printf("\n");
    }
    SetColor(15);
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
    delete[] minPoints;
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }

}
