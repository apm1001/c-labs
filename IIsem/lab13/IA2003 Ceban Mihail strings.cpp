#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <color.h>
#include <string.h>
#include <iostream>


//В задании с ФИО вводить пробел в конце имени и фамилии!!!
void insertSimbol(char *s,int poz,char simb){
    int strSize = strlen(s);
    for(int i=strSize+1;i>poz;i--){
        s[i] = s[i-1];
    }
    s[poz] = simb;
}
void delchar(char *s,int poz){
    int strSize = strlen(s);
    for(int i=poz;i<strSize;i++){
        s[i] = s[i+1];
    }
}

void delnotalpha(char *st){
forhelp:
            for(int i=0;i<strlen(st);i++){
                if(!isalpha(st[i])){
                    delchar(st,i);
                    goto forhelp;
                }
            }
}

void sortalph(char *st){
    char ch;
    for(int i=strlen(st)-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(st[j]>st[j+1]){
                ch = st[j];
                st[j] = st[j+1];
                st[j+1] = ch;
            }
        }
    }
}
void countSimb(char *s,int *gl,int *sogl,int *numb,int *oth,int *punct){
    char voc[] = "euioa";
    char cons[] = "qwrtypsdghjklzxcvbnm";
    char numbers[] = "0123456789";
    char punctSimb[] = ".,!?()'':;-";
    char other[] = "@#$%^&*_+={[}]></~";
    int i=-1;
    char *ptr;
    while(voc[++i]!='\0'){
        ptr = NULL;
        ptr = strchr(s,voc[i]);
        while(ptr){
            (*gl)++;
            ptr = strchr(ptr+1,voc[i]);
        }
    }
    i=-1;
    while(cons[++i]!='\0'){
        ptr = NULL;
        ptr = strchr(s,cons[i]);
        while(ptr){
            (*sogl)++;
            ptr = strchr(ptr+1,cons[i]);
        }
    }
    i=-1;
    while(numbers[++i]!='\0'){
        ptr = NULL;
        ptr = strchr(s,numbers[i]);
        while(ptr){
            (*numb)++;
            ptr = strchr(ptr+1,numbers[i]);
        }
    }
    i=-1;
    while(punctSimb[++i]!='\0'){
        ptr = NULL;
        ptr = strchr(s,punctSimb[i]);
        while(ptr){
            (*punct)++;
            ptr = strchr(ptr+1,punctSimb[i]);
        }
    }
    i=-1;
    while(other[++i]!='\0'){
        ptr = NULL;
        ptr = strchr(s,other[i]);
        while(ptr){
            (*oth)++;
            ptr = strchr(ptr+1,other[i]);
        }
    }
}

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetColor(15);

    int k,n,length=0;
    char ch;
    char str[100],str1[100],num1[10],num2[10],str3[100],str4[100];
    char *ptr1,*ptr2;
    int gl=0,sogl=0,numb=0,oth=0,punct=0;
    int age,month;
    float nr;


M1:
    printf("\nChoose:\n1)22\n2)15\n3)FIO\n4)25\n-->");
    ch = getche();
    switch(ch){
        case '1':
            puts("\nInput a string -->");
            gets(str);
            strcpy(str1,str);
            printf("\nAnswer:\n");
            ptr1=ptr2=NULL;
            ptr1 = strchr(str1,'"');
            while(ptr1){
                ptr2 = strchr(ptr1+1,'"');
                if(ptr2){
                    str1[ptr1-str1] = '\0';
                    strcat(str1,ptr2+1);
                    ptr1 = strchr(str1,'"');
                }
                else{
                    ptr1 = NULL;
                }
            }
            printf("%s",str1);
            break;
        case '2':
            puts("\nInput a string -->");
            gets(str);
            puts("\nInput a word -->");
            gets(str1);
            printf("\nAnswer:\n");

            ptr1 = NULL;
            for(int i=0;str[i]!='\0';i++){
                for(int j=0;str1[j]!='\0';j++){
                    if(str[i]==str1[j]){
                        SetColor(2);
                        break;
                    }
                }
                printf("%c",str[i]);
                SetColor(15);
            }
            countSimb(str1,&gl,&sogl,&numb,&oth,&punct);
            printf("\nNumbers = %i",numb);
            printf("\nGlasnie = %i",gl);
            printf("\nSoglasnie = %i",sogl);
            printf("\nPunct chars = %i",punct);
            printf("\nOther simbols = %i",oth);
            break;
        case '3':
            printf("\nInput first name:");
            gets(str);
            printf("Input second name:");
            gets(str1);
            printf("Input patronymic:");
            gets(str3);
            strcat(str,str1);
            strcat(str,str3);
            printf("%s",str);
            countSimb(str,&gl,&sogl,&numb,&oth,&punct);
            printf("\nGlasnie = %i",gl);
            printf("\nSoglasnie = %i",sogl);
            printf("\n");
            strrev(str3);
            printf("%s",str3);
            printf("\nYour age:");
            scanf("%i",&age);
            printf("Month of birth:");
            scanf("%i",&month);
            nr = age/month;
            printf("Nr - %g",nr);
            printf("\n%s",str4);
            for(int i=0;i<strlen(str3);i++){
                if(fmod(i,nr)==0){
                    strncpy(str4,str3+i,1);
                    printf("%s",str4);
                }

            }
            printf("\n");
            strncpy(str4,str,3);
            puts(str4);
            printf("\nThe string \"%s\" %c \"%s\"",str,strcmp(str4,str)?35:'=',str4);
            printf("\nThe string \"%s\" %c \"%s\"",str,strncmp(str4,str,3)?35:'=',str4);
            break;
        case '4':
            puts("\nInput a string -->");
            gets(str);
            puts("\nInput another string-->");
            gets(str1);
            strlwr(str);
            strlwr(str1);
            delnotalpha(str);
            delnotalpha(str1);
            sortalph(str);
            sortalph(str1);
            printf("\nFirst string sorted:");
            printf("\n%s",str);
            printf("\nSecond string sorted:");
            printf("\n%s",str1);
            strcat(str,str1);
            sortalph(str);
            printf("\nThird string sorted:");
            printf("\n%s",str);
            break;
    }
endPr:
    getche();
}
