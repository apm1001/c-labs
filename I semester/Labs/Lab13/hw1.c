//30.Сколько раз встречается символ , код которого > числа введенного с клавиатуры и  < числа введенного пользователем .

#include <stdio.h>
#include <conio.h>
#include "color.h"
main()
{
    char string[100];
    int n,num1,num2,sum=0;

    printf("Enter the size of string N = "); scanf("%i",&n);
    printf("Enter a string:\n");

    for(int i=0;i<n;i++)
        string[i] = getche();
    m1:
    printf("\nNum1 = "); scanf("%i",&num1);
    printf("Num2 = "); scanf("%i",&num2);
    if (num1>num2){
        printf("Num1 should be less then Num2!!!Try again!");
        goto m1;
    }
    puts("");
    for(int i=0;i<n;i++){
        if(string[i]>num1 && string[i]<num2){
            SetColor(4);
            sum++;
        }
        else SetColor(15);
        printf("%c",string[i]);
    }
    SetColor(15);
    printf("\n\nNumber of symbols that are greater then Num1 and less than Num2: %i",sum);

}
