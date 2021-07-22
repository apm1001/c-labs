#include <stdio.h>
#include <math.h>
#include <color.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//17
main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ClearConsoleToColors(2,7);
    srand(time(NULL));
    int k,n;
    char ch;
    printf("Введите размерность матрицы N = ");
    scanf("%i",&n);
    int a[n][n],i,j,sov[4]={6,28,496,8128};
    int nStroki,sum,min=99999,max=-99999,countK,iFix=1,iMaxSov=0,jMinStolb,vrem;
    int j1,i1,iMaxSev,jMinSouth;
    bool ba,bb;
M1:
    printf("\nВыберите случай:\na)Поменять местами эл-ты столбца с мин-ой суммой эл-ов с эл-тами строки, указанной пользователем, содержащей максимальное количество совершенных чисел(=сумме своих делителей :6=1+2+3) из элементов восточной зоны.\nb)Найти максимальный элемент столбца, указанного пользователем, расположенного в северной области и поменять местами с минимальным элементом строки, введенной пользователем, расположенной в южной области\n-->");
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
    printf("\nМатрица:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j] = (rand()%7);
        }
    }
    SetColor(5);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                printf("%4i",a[i][j]);
        }
        printf("\n");
    }
    SetColor(2);
    if(ba){
        printf("Матрица с восточной зоной :\n");
        SetColor(5);
        countK = 0;
        max = -99999;
        min = 99999;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                sum = 0;
                if(i==j){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i+j == n-1){
                    SetColor(4);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i<j&&i+j>n-1){
                    SetColor(6);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                    if(i==iFix){
                        for(k=0;k<4;k++){
                            if(a[i][j]==sov[k]){
                                countK++;
                                break;
                            }
                        }
                    }
                    else{
                        if(max<countK){
                            max = countK;
                            iMaxSov = iFix;
                        }
                        countK = 0;
                        iFix = i;
                        for(k=0;k<4;k++){
                            if(a[i][j]==sov[k]){
                                countK++;
                                break;
                            }
                        }
                    }
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }

        if(iMaxSov==0){
            printf("\nМатрица не содержит совершенных чисел в восточной зоне!Создайте новую!");
            goto M1;
        }
M2:
        printf("\nВведите номер строки матрицы (0-%i):",n-1);
        scanf("%i",&nStroki);
        if(nStroki!=iMaxSov){
            printf("\nЭта строка не содержит максимальное количество совершенных чисел из восточной зоны!\nСоветую ввести номер строки %i",iMaxSov);
            goto M2;
        }

        //нахождение столбца с минимальной суммой элементов
        for(j=0;j<n;j++){
            sum = 0;
            for(i=0;i<n;i++){
                sum += a[i][j];
            }
            if(sum<min){
                min = sum;
                jMinStolb = j;
            }
        }

        //zamena
        for(i=0;i<n;i++){
            vrem = a[iMaxSov][i];
            a[iMaxSov][i] = a[i][jMinStolb];
            a[i][jMinStolb] = vrem;
            //a[iMaxSov][i] += a[i][jMinStolb];
            //a[i][jMinStolb] = a[iMaxSov][i] - a[i][jMinStolb];
            //a[iMaxSov][i] -= a[i][jMinStolb];
        }
        //vivod
        printf("\nВывод ответа:\n");
        SetColor(5);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j==jMinStolb){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i==iMaxSov){
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
        printf("\nВведите номер столбца матрицы(0-%i):",n-1);
        scanf("%i",&j1);
        printf("\nВведите номер строки матрицы(0-%i):",n-1);
        scanf("%i",&i1);

        printf("Матрица с северной и южной зонами :\n");
        SetColor(5);
        countK = 0;
        max = -99999;
        min = 99999;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                sum = 0;
                if(i==j){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i+j == n-1){
                    SetColor(4);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i<j&&i+j<n-1){
                    SetColor(6);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                    if(j==j1&&a[i][j]>max){
                        max = a[i][j];
                        iMaxSev = i;
                    }
                }
                else if(i>j&&i+j>n-1){
                    SetColor(8);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                    if(i==i1&&min>a[i][j]){
                        min = a[i][j];
                        jMinSouth = j;
                    }
                }
                else{
                    printf("%4i",a[i][j]);
                }
            }
            printf("\n");
        }
        vrem = a[iMaxSev][j1];
        a[iMaxSev][j1] = a[i1][jMinSouth];
        a[i1][jMinSouth] = vrem;

        SetColor(2);
        printf("\nВывод ответа:\n");
        SetColor(5);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==i1&&j==jMinSouth){
                    SetColor(3);
                    printf("%4i",a[i][j]);
                    SetColor(5);
                }
                else if(i==iMaxSev&&j==j1){
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

M3:
    printf("\nПовторить ?(1-да)(2-завершить программу)-->");
    scanf("%i",&k);
    switch(k){
    case 1:goto M1;
    case 2:break;
    default:printf("Вы ввели неверное значение, попробуйте еще раз!!!");goto M3;
    }
}
