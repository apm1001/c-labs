#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<gotoxy.h>

void createDinMatr(int**& x,int n){
   x = new int *[n];
    for(int i=0;i<n;i++){
        x[i] = new int [n];
    }
}
void deleteDinMatr(int **x,int n){
    for (int i=0; i<n; i++){
        delete [] x[i];
    }
    delete []x;
}

void createDinVect(int*& x,int n){
   x = new int[n];
}
void deleteDinVect(int *x){
    delete []x;
}

void outputArr(int *x,int n){
    printf("\nArray:\n");
    for(int i=0;i<n;i++){
        printf("%6i",x[i]);
    }
}
void outputMatr(int **x,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6i",x[i][j]);
        }
        printf("\n");
    }
}
void inputArrRand(int *x,int n){
    for(int i=0;i<n;i++){
        x[i] = rand()%100-20;
    }
}
void inputMatrRand(int **x,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j] = (rand()%50)-20;
        }
    }
}
void inputArrKeyB(int *x,int n,char ch){
    for(int i=0;i<n;i++){
        printf("%c(%i) = ",ch,i);
        scanf("%i",&x[i]);
    }
}
void inputMatrKeyB(int **x,int n, char ch){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c(%i)(%i) = ",ch,i,j);
            scanf("%i",&x[i][j]);
        }
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
int SummArr(int *x,int n){
    int sum=0;
    for(int i=0;i<n;i++){
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



