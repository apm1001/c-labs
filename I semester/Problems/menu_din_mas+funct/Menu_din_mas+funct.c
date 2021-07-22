#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include<conio.h>
#include<malloc.h>
#include<stdbool.h>
main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char c;
    int k,n,m,**a,i,j;


    void first_func()
    {
        printf("\nКоличество строк n = "); scanf("%i",&n);
        printf("Количество столбцов m = "); scanf("%i",&m);
        a = (int **)malloc(n*sizeof(int *));
        for(i = 0; i < n; i++)
        {
            a[i] = (int *)malloc(m*sizeof(int));
        }
    }
    void second_func()
    {
        printf("\nВведите элементы массива :\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("a[%i,%i] = ",i,j);
                scanf("%i",&a[i][j]);
            }
        }
    }
    void third_func()
    {
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                a[i][j] = rand()%100;
            }
        }
    }
    void fourth_func()
    {
        int max,min;
        for(i=0;i<n-1;i++){
            for(j=0;j<(n-1-i);j++){
                if(a[j][0]>a[j+1][0]){
                    max = a[j][0];min=a[j+1][0];
                    a[j][0] = min;
                    a[j+1][0] = max;
                }
                if(a[j][m-1]>a[j+1][m-1]){
                    max = a[j][m-1];
                    a[j][m-1] = a[j+1][m-1];
                    a[j+1][m-1] = max;
                }
            }
        }
    }
    void fifth_func()
    {
        printf("\nМассив A:\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%4i",a[i][j]);
            }
            printf("\n");
        }
    }
    void sixth_func()
    {
        for (i = 0; i < n; i++)
            free(a[i]);
        free(a);
    }
Menu:
    printf("\nВыберите опцию:\n1. Динамическое выделение памяти для двумерного массива\n2. Ввод элементов массива с клавиатуры\n3. Заполнение массива случайными числами\n4. Сортировка элементов массива (по вариантам)\n5. Вывод элементов массива на экран\n6. Освобождение памяти, выделенной для массива\n7. Окончание работы программы\n--->");
    c = getch();
    switch(c){
    case '1':
        first_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '2':
        second_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '3':
        third_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '4':
        fourth_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '5':
        fifth_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '6':
        sixth_func();
        printf("\nОпция выполнена успешно!");
        goto Menu;
    case '7': break;
    default: printf("\nВы ввели недопустимое значение!Попробуйте снова!"); goto Menu;
    }
}
