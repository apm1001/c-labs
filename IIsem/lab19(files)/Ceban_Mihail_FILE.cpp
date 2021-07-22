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

void dell(char *s,char *s1,int i1, int j1,int length){
    int dif=j1-i1+1;
    length-=dif;
    for(int i=i1;s[i+dif]!='\0';i++){
        s1[i] = s[i+dif];
    }
    s1[length] = '\0';
}

int main(){
    FILE *f;
    char str1[100],str[100];
    int len;

    f=fopen("1.txt","w+");
    gets(str);
    fprintf(f,"%s\n",str);
    printf("\nThe file contains this string:\n");
    rewind(f);
    while(!feof(f)){
        fputc(fgetc(f),stdout);
    }
    len = strlen(str);
    forI{
        str1[i] = str[i];
    }
            str1[len]='\0';
    forI{
        if(str[i]=='"'){
            for(int j=i+1;str[j]!='\0';j++){
                if(str[j]=='"'){
                    dell(str,str1,i,j,len);
                }
            }
        }
    }
    fprintf(f,"\nAnswer:\n");
    fprintf(f,"%s",str1);

}
