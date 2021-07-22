#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <workWithOMArray.h>
#include <color.h>

#define forI for(int i=0;i < m;i++)
#define forJ for(int j=0;j < m;j++)

bool isExcess(int x){
    int sum=0;
    if(x<0){
        x*=-1;
    }
    for(int i=1;i<=x/2;i++){
        if(x%i==0){
            sum+=i;
        }
    }

    if(sum>x){
        return true;
    }
    else{
        return false;
    }
}

bool isSov(int x){
    int sov[4]={6,28,496,8128};
    bool b=false;
    for(int i=0;i<4;i++){
        if(x==sov[i]){
            b = true;
            break;
        }
    }
    if(b){
        return true;
    }
    else{
        return false;
    }
}
int elementsBetween(int i1,int j1,int i2,int j2,int n){
    int dist;

    if(i1==i2){
        dist = abs(j2-j1)-1;
    }
    else{
        if(i1<i2){
            dist = n-j1-1+(i2-i1-1)*n+j2;
        }
        else{
            dist = n-j2-1+(i1-i2-1)*n+j1;
        }
    }
    return dist;
}
int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);
Menu:
    int k,m;
    char ch;
    printf("\nВведите размерность матрицы N = ");
    scanf("%i",&m);
    printf("\nВыберите способ ввода массива:\n1 - с клавиатуры\n2 - случайно -->");
    scanf("%i",&k);
    int a[20][20];
    int maxim=-999999,minim=999999,sum,pr;
    bool b1=false,b2=false;
    bool fromMaxToMin=false;
        int kMax=0,kMin=0,iMax,iMin,jMax,jMin;
    switch(k){
    case 1:
        inputMatrKeyB(a,m);
        break;
    case 2:
        inputMatrRand(a,m);
        break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
    outputMatr(a,m);

M1:
    printf("\nВыберите случай:\n1)max(a(i,1),a(i,3),...) в каждой строке если этот эл-т является избыточным(меньше суммы своих правильных делителей)\n2)min(sum(элементов совершенных, Pr(эл-ов, больших суммы своих правильных делителей) по столбцам\n3)Количество элементов расположенных между вторым максимальным от начала матрицы и предпоследним минимальным в каждой зоне\n-->");
    ch = getche();
    switch(ch){
    case '1':
        printf("\nВывод Ответа:\n");
        SetColor(1);
        forI{
            SetColor(1);
            maxim=-999999;
            forJ{
                if(isExcess(a[i][j])&&j%2==1){
                    SetColor(2);
                    printf("%4i",a[i][j]);
                    SetColor(1);
                    maxim = Max(maxim,a[i][j]);
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            SetColor(15);
            if(maxim!=-999999){
                printf("    Max = %i",maxim);
            }
            else{
                printf("    Таких чисел нет в этой строке!!!");
            }
            printf("\n");
        }
        break;

    case '2':
        printf("\nВывод Ответа:\n");
        SetColor(4);
        minim=999999;
        forI{
            forJ{
                if(isSov(a[i][j])){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(4);
                }
                else if(!isExcess(a[i][j])){
                    SetColor(2);
                    printf("%4i",a[i][j]);
                    SetColor(4);
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
        SetColor(15);
        printf("\n");

        forJ{
            pr = 1;
            sum = 0;
            b1=b2=false;
            forI{
                if(isSov(a[i][j])){
                    sum+=a[i][j];
                    b2 = true;
                }
                else if(!isExcess(a[i][j])&&a[i][j]!=0){
                    pr*=a[i][j];
                    b1 = true;
                }
            }
            if(b1&&b2){
                printf("%4i",Min(pr,sum));
            }
            else if(b1){
                printf("%4i",pr);
            }
            else if(b2){
                printf("%4i",sum);
            }
            else{
                printf("   N");
            }
        }

        break;
    case '3':
        printf("\nВывод Ответа:\n");
        SetColor(1);
        maxim=-999999;
        k=0;
        minim=999999;
        forI{
            forJ{
                if(a[i][j]>maxim){
                    maxim = a[i][j];
                }
                if(a[i][j]<minim){
                    minim = a[i][j];
                }
            }
        }
        forI{
            forJ{
                if(a[i][j]==maxim){
                    SetColor(2);
                    printf("%4i",a[i][j]);
                    SetColor(1);
                    kMax++;
                }
                else if(a[i][j]==minim){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(1);
                    kMin++;
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
        SetColor(15);
        if(kMax<2||kMin<2){
            printf("Матрица не соответствует условию, необходимы два одинаковых минимальных и два максимальных элементов!!\n");
        }
        else{

            kMax=0;
            forI{
                forJ{
                    if(a[i][j]==maxim){
                        kMax++;
                        if(kMax==2){
                            jMax = j;
                            iMax = i;
                        }
                    }
                    if(a[i][j]==minim){
                        k++;
                        if(k==kMin-1){
                            iMin = i;
                            jMin = j;
                        }
                    }
                }
            }
            printf("\nКоличество элементов, расположенных между вторым максимальным и предпоследним минимальным: %i",elementsBetween(iMax,jMax,iMin,jMin,m));
        }
        break;
    default:printf("Недопустимое значение, попробуйте еще раз!!");goto M1;
    }
M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto Menu;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
