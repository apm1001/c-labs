#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define forLoop for(int i=0;i < n;i++)

struct mylist
{
    int a;
    mylist *next;
};

mylist *first, *last;

void create_list(int i,char chr)
{
    mylist *curent;
    if(!first){
        first = new mylist;
        if (chr == 'k'){
            printf("\na[%i] = ",i);
            scanf("%i",&first->a);
        }
        else{
            first->a = rand()%100-20;
        }

        last = first;
    }
    else{
        curent = new mylist;
        if (chr == 'k'){
            printf("a[%i] = ",i);
            scanf("%i",&curent->a);
        }
        else{
            curent->a = rand()%100-20;
        }
        last->next = curent;
        last = curent;
    }
    last->next = 0;
}

bool del(int x,int y){
    if(x%y==0){
        return true;
    }
    else{
        return false;
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

void outputArr(){
    mylist *c;
    c = first;
    while(c){
        printf("%5i",c->a);
        c = c->next;
    }
    printf("\n");
}

void f1(int n){
    int k,min=999999,max=-999999;
    printf("\nK = ");
    scanf("%i",&k);
    mylist *c;
    c = first;
    int p;
    forLoop{
        p = 2*i+1+k;
        c = first;
        if(p>=n) break;
        else{
            for(int j = 0;j<p;j++){
                c = c->next;
            }
            min = Min(c->a,min);
        }
    }
    forLoop{
        i++;
        p = 2*i+1;
        c = first;
        if(p>=n) break;
        else{
            p = 2*i+1;
            for(int j = 0;j<p;j++){
                c = c->next;
            }
            max = Max(c->a,max);
        }
    }
    printf("Max(%i,%i) = %i",min,max,Max(min,max));
}
void f2(int n){
    mylist *c;
    c = first;
    int sum=0,pr=1;
    forLoop{
        if(del(c->a,3))sum+=c->a;
        if(del(c->a,5)&&c->a!=0)pr*=c->a;
        c = c->next;
    }
    printf("\nMax(%i,%i) = %i",sum,pr,Max(sum,pr));
}
void f3(int n){
    mylist *c;
    c = first;
    printf("\nРешение\n");
    forLoop{
        if(c->a==0){
            c->a=5;
        }
        c = c->next;
    }
    outputArr();
}
void f4(int n){
    mylist *c;
    c = first;
    int pr=1,sum=0,k=0;
    int p,t;
    printf("\np = ");
    scanf("%i",&p);
    printf("t = ");
    scanf("%i",&t);
    forLoop{
        if(c->a<0){
            pr*=c->a;
        }
        c = c->next;
        if(i+1<n-1){
            c = c->next;
            i++;
        }
    }
    c = first;
    if(pr>0){
        c = first;
        forLoop{
            if(del(c->a,p))sum+=c->a;
            c = c->next;
        }

        if(sum<t){
            printf("\nСумма элементов, делящихся на %i (%i) меньше %i",p,sum,t);
        }
        else{
            printf("\nСумма элементов, делящихся на %i (%i) не меньше %i",p,sum,t);
        }
    }
    else{
        printf("\nПроизведение отрицательных меньше нуля!!");
    }

}
int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int k,N;
    char ch;
    printf("\nВведите размерность массива N = ");
    scanf("%i",&N);
    printf("\nВыберите способ ввода массива:\n1 - с клавиатуры\n2 - случайно -->");
    scanf("%i",&k);
    switch(k){
    case 1:
        for(int i=0;i<N;i++){
            create_list(i,'k');
        }
        break;
    case 2:
        for(int i=0;i<N;i++){
            create_list(i,'r');
        }
        break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
    outputArr();

M1:
    printf("\nВыберите случай:\n1)max(min(a[1+k],a[3+k],..),max(нечет))\n2)max(summ(эл-ов делящ. на 3), произведения элементов делящихся на 5)\n3)все эл-ты - 0 заменить на 5\n4)если произведение(отрицательных на четных поз)>0, определить если сумма элементов делящихся на p < t\n-->");
    ch = getche();
    switch(ch){
    case '1':
        f1(N);
        break;
    case '2':
        f2(N);
        break;
    case '3':
        f3(N);
        break;
    case '4':
        f4(N);
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M1;
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
