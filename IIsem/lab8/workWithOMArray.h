#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<color.h>
#include<gotoxy.h>

#define forLoop for(int i=0;i < n;i++)


void outputArr(int x[20],int n){
    printf("\nArray:\n");
    forLoop{
        printf("%6i",x[i]);
    }
}
void inputArrRand(int x[20],int n){
    forLoop{
        x[i] = rand()%100-20;
    }
}
void inputArrKeyB(int x[20],int n){
    forLoop{
        printf("A(%i) = ",i);
        scanf("%i",&x[i]);
    }
}
bool del(int x,int y){
    if(x%y==0){
        return true;
    }
    else{
        return false;
    }
}
int maxDel(int x){
    int k=1,i;
    for(i=1;i<=x/2;i++){
        if(x%i==0){
            k++;
        }
    }
    return k;
}
int SummArr(int x[20],int n){
    int sum=0;
    forLoop{
        sum+=x[i];
    }
    return sum;
}
int Max(int o,int y){
    if(o>y){
        return o;
    }
    else return y;
}

int Min(int o,int y){
    if(o>y){
        return y;
    }
    else return o;
}
f1(){

}

