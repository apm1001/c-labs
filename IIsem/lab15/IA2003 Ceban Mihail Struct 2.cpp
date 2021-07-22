#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
struct address{
    char city[20];
    char street[20];
    int nr;
};
struct delivery{
    struct address addr;
    char tel[15];
    char payment[10];
};

struct charact{
    int length;
    int width;
    int height;
};

struct tip{
    char name[20];
    struct charact har;
    float price;
};

struct mebel{
    struct tip type;
    char manufacturer[20];
    int warranty;
    struct delivery del;

};
void input(struct mebel x[],int m,int n){
    bool b=false;
    for(int i=m;i<n;i++){
        printf("\nOrder nr. %i\n",i+1);
        b=false;
        while(!b){
            printf("Name of furniture:");scanf("%s",x[i].type.name);
            for(int j=0;j<strlen(x[i].type.name);j++){
                b = isalpha(x[i].type.name[j]);
                if(!b){
                    printf("Wrong name!Try again!Only letters required!\n");
                    break;
                }
            }
        }
        printf("Length of furniture(in cm):");scanf("%i",&x[i].type.har.length);
        printf("Width of furniture(in cm):");scanf("%i",&x[i].type.har.width);
        printf("Height of furniture(in cm):");scanf("%i",&x[i].type.har.height);
        printf("Price of furniture(in dollars):");scanf("%f",&x[i].type.price);
        b=false;
        while(!b){
            printf("Name of manufacturer:");scanf("%s",x[i].manufacturer);
            for(int j=0;j<strlen(x[i].manufacturer);j++){
                b = isalpha(x[i].manufacturer[j]);
                if(!b){
                    printf("Wrong name!Try again!Only letters required!\n");
                    break;
                }
            }
        }
        printf("Telephone number:");scanf("%s",x[i].del.tel);
        printf("Warranty(months):");scanf("%i",&x[i].warranty);
        b=false;
        while(!b){
            printf("Payment method(card or cash):");scanf("%s",x[i].del.payment);
            if(!strcmp(x[i].del.payment,"card")||!strcmp(x[i].del.payment,"cash")){
                b = true;
            }
            else{
                printf("You need to enter words cash or card!\n");
            }
        }
        printf("Address of delivery:\n");
        printf("City:"); scanf("%s",x[i].del.addr.city);
        printf("Street:"); scanf("%s",x[i].del.addr.street);
        printf("Nr. of house:"); scanf("%i",&x[i].del.addr.nr);


    }
}
void output(struct mebel x[],int m, int n){
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    SetColor(3);
    printf("\n|    Name    |   Length   |   Width   |   Height   |   Price   |  Manufacturer  |   Warranty   |  Tel. number  | Payment |   City   |    Street    |Nr. of house|");
    SetColor(15);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = m; i < n; i++)
    {
        printf("\n|%12s|%8i sm.|%7i sm.|%8i sm.|%10.2f$|%16s|%7i months|%15s|%9s|%10s|%14s|%12i|",x[i].type.name,x[i].type.har.length,x[i].type.har.width,x[i].type.har.height,
               x[i].type.price,x[i].manufacturer,x[i].warranty,x[i].del.tel,x[i].del.payment,x[i].del.addr.city,x[i].del.addr.street,x[i].del.addr.nr);
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}

void findEl(struct mebel x[],int n){
    char s[20];
    bool b=false;
    printf("\nEnter the name of furniture:");
    scanf("%s",&s);
    for(int i=0;i<n;i++){
        if(!strcmp(x[i].type.name,s)){
            output(x,i,i+1);
            b = true;
            break;
        }
    }
    if(!b){
        printf("The furniture with such name doesn't exist!!!");
    }
}
void delEl(struct mebel x[],int n){
    char s[20];
    int index=0;
    bool b=false;
    printf("\nEnter the name of furniture, that you want to delete:");
    scanf("%s",&s);
    for(int i=0;i<n;i++){
        if(!strcmp(x[i].type.name,s)){
            b = true;
            index = i;
            break;
        }
    }
    if(!b){
        printf("The furniture with such name doesn't exist!!!");
    }
    else{
        for(int i=index;i<n-1;i++){
            x[i] = x[i+1];
        }
    }

}
int main(){
    SetColor(15);
    int n=2,e=3,m=0;
    printf("Type number of orders:");scanf("%i",&n);
    struct mebel a[10];
    struct mebel b[10];
    int k,menuCase;
M1:
    printf("1)Example\n2)Input struct.\n-->");
    scanf("%i",&k);
    switch(k){
    case 1:
        for(int i=0;i<e;i++){
            b[i].type.name = {'C','h','a','i','r'};
            b[i].type.har.length = 100;
            b[i].type.har.height = 150;
            b[i].type.har.width = 50;
            b[i].type.price = 15.25;
            b[i].manufacturer = {'J','y','s','k'};
            b[i].warranty = 13;
            b[i].del.addr.city = {'C','h','i','s','i','n','a','u'};
            b[i].del.addr.street = {'D','a','c','i','a'};
            b[i].del.addr.nr = 24;
            b[i].del.payment = {'c','a','s','h'};
            b[i].del.tel = {'0','2','2','3','4','5','6','7'};
        }
        b[1].type.name = {'D','e','s','k'};
        b[2].type.name = {'B','e','d'};
        break;
    case 2:
        input(a,m,n);
        break;
    default:
        printf("Wrong value! Try again!\n");
        goto M1;
    }
Menu:
    printf("\nMenu:\n0)Exit\n1)Output struct\n2)Find element by the name\n3)Insert one element to struct\n4)Delete an element in the struct\n-->");
    scanf("%i",&menuCase);
    switch(menuCase){
    case 0:
        goto End;
        break;
    case 1:
        if(k==1){
            output(b,m,e);
        }
        else{
            output(a,m,n);
        }
        break;

    case 2:
        if(k==1){
            findEl(b,e);
        }
        else{
            findEl(a,n);
        }
        break;
    case 3:
        if(k==1){
            input(b,e,e+1);
            e++;
        }
        else{
            input(a,n,n+1);
            n++;
        }
        break;
    case 4:
        if(k==1){
            delEl(b,e);
            e--;
        }
        else{
            delEl(a,n);
            n--;
        }
        break;

    }
    goto Menu;



End:
    getche();

}
