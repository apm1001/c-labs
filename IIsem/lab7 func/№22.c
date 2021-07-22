#include<stdio.h>
#include<stdlib.h>
#include<bool.h>
#include<time.h>
#include<color.h>
#include<gotoxy.h>

#define forLoop for(int i=0;i < n;i++)


int outputArr(int n,int x[n]){
    forLoop{
        printf("%6i",a[i]);
    }
}
void inputArrRand(int n,int x[n]){
    forLoop{
        x[i] = rand()%100;
    }
}
int inputArrKeyB(int n,int x[n]){
    forLoop{
        printf("A(%i) = ",i);
        scanf("%i",&x[i]);
    }
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
int SummArr(int n,int a[n]){
    int sum=0;
    forLoop{
        sum+=a[i];
    }
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
main(){
Menu:

}
