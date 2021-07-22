#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
void inputKey(int *x,int n,int j,char ch){
        if(j<n){
            printf("%c[%i] = ",ch,j);
            scanf("%i",&x[j]);
            inputKey(x,n,j+1,ch);
        }
}
void inputRand(int *x,int n, int j){
        if(j<n){
            x[j] = rand()%50-10;
            inputRand(x,n,j+1);
        }
}
void out(int *x,int n, int j){
        if(j<n){
            printf("%5i",x[j]);
            out(x,n,j+1);
        }
}
int sum(int *x,int *y,int n,int j){
    if(j==n-1){
        return x[j]*y[j]+j;
    }
    return (x[j]*y[j]+j)*sum(x,y,n,j+1);
}
float sum1(int *x,int *y,int n,int i){
    if(i==n){
        return n/sum(x,y,i,0);
    }
    return (float)(i+1)/sum(x,y,i+1,0)+sum1(x,y,n,i+1);
}
float ss(int current, int n)
{
    if(current<n){
        return current + ss(current+3,n);
    }
}
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k, n,*a,*b,i=0,m,p;
    printf("Type dimension of array N = ");
    scanf("%i",&n);
    a = new int [n];
    b = new int [n];
    printf("Input with keyboard or random?(1 | 2)\n-->");
    scanf("%i",&k);
    if(k==1){
        inputKey(a,n,0,'a');
        inputKey(b,n,0,'b');
    }
    else{
        inputRand(a,n,0);
        inputRand(b,n,0);
    }
    printf("Array A:\n");
    out(a,n,0);
    printf("\nArray B:\n");
    out(b,n,0);

    printf("\nAnswer: %f",sum1(a,b,n,0));

M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }

}
