#include <stdio.h>
#include <string.h>
main()
{
    int length,sum = 0,count;
    char string[100];
    char *p,*p1,*start;

    printf("Enter a string:\n");
    gets(string);

    count = 0; start = string;
    while (1) {
        p = strchr(start, 'b');
        p1 = strchr(start, 'B');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'B' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'c');
        p1 = strchr(start, 'C');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'C' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'd');
        p1 = strchr(start, 'D');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'D' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'f');
        p1 = strchr(start, 'F');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'F' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'g');
        p1 = strchr(start, 'G');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'G' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'h');
        p1 = strchr(start, 'H');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'H' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'j');
        p1 = strchr(start, 'J');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'J' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'k');
        p1 = strchr(start, 'K');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'K' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'l');
        p1 = strchr(start, 'L');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'L' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'm');
        p1 = strchr(start, 'M');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'M' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'n');
        p1 = strchr(start, 'N');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'N' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'p');
        p1 = strchr(start, 'P');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'P' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'q');
        p1 = strchr(start, 'Q');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'Q' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'r');
        p1 = strchr(start, 'R');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'R' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 's');
        p1 = strchr(start, 'S');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'S' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
   while (1) {
        p = strchr(start, 't');
        p1 = strchr(start, 'T');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'T' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'v');
        p1 = strchr(start, 'V');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'V' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'w');
        p1 = strchr(start, 'W');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'W' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'x');
        p1 = strchr(start, 'X');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'X' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'y');
        p1 = strchr(start, 'Y');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'Y' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }
    count = 0; start = string;
    while (1) {
        p = strchr(start, 'z');
        p1 = strchr(start, 'Z');
        if (p1==NULL)
            if (p==NULL){
                if (count!=0) printf("\nAmmount of simbols 'Z' = %d",count);
                break;
            }
            else start = p+1;
        else if (p==NULL) start = p1+1;
                else if (p1>p) start = p+1;
                        else start = p1+1;;
        count++; sum++;
    }

    printf("\n---------------------------------------------------------------------------\n");
    printf("Total consonant characters = %i",sum);

}
