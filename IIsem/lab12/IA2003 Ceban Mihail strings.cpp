#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <color.h>
#include <iostream>
#define forI for(int i=0;str[i]!='\0';i++)
#define forJ for(int j=0;j < n;j++)

int getSize(char *st){
    int k=0;
    for(int i=0;st[i]!='\0';i++){
        k++;
    }
    return k;
}

int findRez(char *s,int i1,int *poz1,int *poz2){
    int count=-1,rezult=0,k=0;
    char num[10];
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='+'){
            count++;
        }
        if(!(*poz1)&&i1!=0&&count==i1-1){
            *poz1 = i+1;
        }
        if(!(*poz2)&&count==i1){
            *poz2=i;
        }
    }
    if((*poz2)==0){
        *poz2 = getSize(s)+1;
    }
    if(*poz1!=0){
        for(int i=0;i<(*poz1);i++){
            if(s[i]=='+'){
                num[k]='\0';
                k=0;
                rezult+=atoi(num);
            }
            else{
                num[k] = s[i];
                k++;
            }
        }
    }
    k=0;
    if((*poz2)!=getSize(s)+1){
        for(int i = *poz2+1;s[i]!='\0';i++){
            if(s[i]=='+'||s[i+1]=='\0'){
                if(s[i+1]=='\0'){
                    num[k]=s[i];
                    num[k+1]='\0';
                }
                else{
                    num[k]='\0';
                }
                k=0;
                rezult+=atoi(num);
            }
            else{
                num[k] = s[i];
                k++;
            }
        }
    }
    return rezult;

}
void insertSimbol(char *s,int poz,char simb){
    int strSize = getSize(s);
    for(int i=strSize+1;i>poz;i--){
        s[i] = s[i-1];
    }
    s[poz] = simb;
}
void countSimb(char *s,int *gl,int *sogl,int *numb,int *oth,int *punct){
    for(int i = 0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            (*numb)++;
        }
        else if(s[i]=='А'||s[i]=='а'||s[i]=='У'||s[i]=='у'||s[i]=='Е'||s[i]=='е'||s[i]=='Э'||s[i]=='э'||s[i]=='О'||s[i]=='о'||s[i]=='Ы'||s[i]=='ы'||s[i]=='Я'||s[i]=='я'||s[i]=='И'||s[i]=='и'||s[i]=='Ю'||s[i]=='ю'||s[i]=='Ё'||s[i]=='ё'){
            (*gl)++;
        }
        else if(s[i]=='Й'||s[i]=='й'||s[i]=='Ц'||s[i]=='ц'||s[i]=='К'||s[i]=='к'||s[i]=='Н'||s[i]=='н'||s[i]=='Г'||s[i]=='г'||s[i]=='Ш'||s[i]=='ш'||s[i]=='Щ'||s[i]=='щ'||s[i]=='З'||s[i]=='з'||s[i]=='Х'||s[i]=='х'||s[i]=='Ъ'||s[i]=='ъ'||s[i]=='Ф'||s[i]=='ф'||s[i]=='В'||s[i]=='в'||s[i]=='П'||s[i]=='п'||s[i]=='Р'||s[i]=='р'||s[i]=='Л'||s[i]=='л'||s[i]=='Д'||s[i]=='д'||s[i]=='Ж'||s[i]=='ж'||s[i]=='Ч'||s[i]=='ч'||s[i]=='С'||s[i]=='с'||s[i]=='М'||s[i]=='м'||s[i]=='Т'||s[i]=='т'||s[i]=='Ь'||s[i]=='ь'||s[i]=='Б'||s[i]=='б'){
            (*sogl)++;
        }
        else if(ispunct(s[i])){
            (*punct)++;
        }
        else{
            (*oth)++;
        }
    }
}
void findWord(char *s,char *w){
    bool isEqualChar=false;

    for(int i=0;s[i]!='\0';i++){
        isEqualChar = false;
        for(int j=0;w[j]!='\0';j++){
            if(w[j]==s[i]){
                isEqualChar = true;
                break;
            }
        }
        if(isEqualChar){
            SetColor(2);
            printf("%c",s[i]);
            SetColor(15);
        }
        else{
            printf("%c",s[i]);
        }
    }
}



void dell(char *s,char *s1,int i1, int j1,int length){
    int dif=j1-i1+1;
    length-=dif;
    for(int i=i1;s[i+dif]!='\0';i++){
        s1[i] = s[i+dif];
    }
    s1[length] = '\0';
}


int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);

    int k,n,length=0;
    char ch;
    char str[500],str1[500],num1[10],num2[10];
    int gl=0,sogl=0,numb=0,oth=0,punct=0;
    int rez,pluses,poz1,poz2,rezTest,rez2,k1,k2,plusPoint;
    bool wrongInput=false,isAnswer=false;


M1:
    printf("\nВыберите случай:\n1)22.Удалить все символы расположенные между \"\"\n2)15.Найти все буквы введенного слова в введенной строке символов и подсчитать сколько символов каждого типа в этом слове\n3)43.Проверить правильность выражения сложения и по необходимости исправить\n-->");
    ch = getche();
    switch(ch){
        case '1':
            puts("\nВведите строку на русском -->");
            gets(str);
            length=0;
            forI{
                length++;
                str1[i] = str[i];
            }
            str1[length]='\0';
            forI{
                if(str[i]=='"'){
                    for(int j=i+1;str[j]!='\0';j++){
                        if(str[j]=='"'){
                            dell(str,str1,i,j,length);
                        }
                    }
                }
            }
            printf("\nВывод ответа:\n");
            printf("%s",str1);
            break;
        case '2':
            puts("\nВведите строку на русском -->");
            gets(str);
            puts("\nВведите слово на русском -->");
            gets(str1);
            printf("\nВывод ответа:\n");
            findWord(str,str1);
            countSimb(str1,&gl,&sogl,&numb,&oth,&punct);
            printf("\nКоличество цифр = %i",numb);
            printf("\nКоличесвто гласных = %i",gl);
            printf("\nКоличество согласных = %i",sogl);
            printf("\nКоличество символов пунктуации = %i",punct);
            printf("\nКоличество других символов = %i",oth);
            break;
        case '3':
            puts("\nВведите выражение -->");
            gets(str);
            printf("Введите ответ -->");
            scanf("%i",&rez);
            pluses=0;
            forI{
                if(str[i]=='+'){
                    pluses++;
                }
                else if(!isdigit(str[i])){
                    wrongInput = true;
                    break;
                }
            }
            if(wrongInput){
                printf("\nВы ввели недопустимое выражение!");
                goto endPr;
            }
            k=0;
            rezTest=0;
            forI{
                if(str[i]=='+'||str[i+1]=='\0'){
                    if(str[i+1]=='\0'){
                        num1[k]=str[i];
                        num1[k+1]='\0';
                    }
                    else{
                        num1[k]='\0';
                    }
                    k=0;
                    rezTest+=atoi(num1);
                }
                else{
                    num1[k] = str[i];
                    k++;
                }
            }
            if(rezTest==rez){
                printf("\nОшибок нет!");
                goto endPr;
            }
            for(int i=0;i<=pluses;i++){
                poz1=poz2=0;
                rez2 = findRez(str,i,&poz1,&poz2);
                for(int j=0;j<poz2-poz1-1;j++){
                    k1=k2=0;
                    for(k=poz1;k<poz2-j-1;k++){
                        num1[k1] = str[k];
                        k1++;
                    }
                    for(k=poz2-j-1;k<poz2;k++){
                        num2[k2] = str[k];
                        k2++;
                    }
                    num1[k1] = '\0';
                    num2[k2] = '\0';
                    rezTest = rez2 + atoi(num1) + atoi(num2);
                    if(rezTest == rez){
                        plusPoint = poz1+k1;
                        isAnswer = true;
                    }
                    if(isAnswer){
                        break;
                    }
                }
                if(isAnswer){
                    insertSimbol(str,plusPoint,'+');
                    printf("\nОтвет: %s",str);
                    break;
                }
            }
            if(!isAnswer){
                printf("\nВы ввели выражение не по условию(пропущен может быть только один '+')!!!");
            }
            break;
    }
endPr:
    getche();
}
