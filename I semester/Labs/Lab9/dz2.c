#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
main(){
    setlocale(LC_ALL,"Russian");
    char ch;
    int k;
    bool b=false;
Menu:
    printf("\nEnter a letter: ");
    ch = getch();
    printf("\nYour letter is '%c'",ch);
    if ((ch>96) && (ch<123)){
        b = true;
        switch (ch){
            case 97: case 101: case 105: case 111: case 117:
                printf("\n��������� ����� ����������� ��������, �����, �������"); break;
            default: printf("\n��������� ����� ����������� ��������, �����, ���������");
        }
    }
    if ((ch>64) && (ch<91)){
        b = true;
        switch (ch){
            case 65: case 69: case 73: case 79: case 85:
                printf("\n��������� ����� ����������� ��������, �������, �������"); break;
            default: printf("\n��������� ����� ����������� ��������, �������, ���������");
        }
    }
    if ((ch>191) && (ch<224)){
        b = true;
        switch (ch){
            case 192: case 197: case 200: case 206: case 211: case 219: case 221: case 222: case 223:
                printf("\n��������� ����� �������� ��������, �������, �������"); break;
            default: printf("\n��������� ����� �������� ��������, �������, ���������");
        }
    }
    if ((ch>223) && (ch<256)){
        b = true;
        switch (ch){
            case 224: case 229: case 232: case 238: case 243: case 251: case 253: case 254: case 255:
                printf("\n��������� ����� �������� ��������, �����, �������"); break;
            default: printf("\n��������� ����� �������� ��������, �����, ���������");
        }
    }
    if (!b){
        printf("\n�� ����� �� �����!!!");
        goto Menu;
    }
    return 0;
}
