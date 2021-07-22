#include <color.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct charact{
    int length;
    int width;
    int height;
};

struct mylist
{
    charact a;
    mylist *next;
};

mylist *first, *last;

void create_list(int i)
{
    mylist *curent;
    bool b=false;
    if(!first){
        first = new mylist;
        printf("    length = ");
        scanf("%i",&first->a.length);
        printf("    width = ");
        scanf("%i",&first->a.width);
        printf("    height = ");
        scanf("%i",&first->a.height);
        last = first;

    }
    else{
        curent = new mylist;
        printf("    length = ");
        scanf("%i",&curent->a.length);
        printf("    width = ");
        scanf("%i",&curent->a.width);
        printf("    height = ");
        scanf("%i",&curent->a.height);
        last->next = curent;
        last = curent;
    }
    last->next = 0;
}

void output_struct(){
    mylist *c;
    c = first;
    int i = 1;
    while(c){
        printf("\n%i furn.:",i);
        i++;
        printf("\n    length %i",c->a.length);
        printf("\n    width %i",c->a.width);
        printf("\n    height %i",c->a.height);
        c = c->next;
    }
    printf("\n");
}


void delEl(int n){
    mylist *c;
    mylist *prev;
    c = first;
    prev = first;
    int index=0;
    bool b=false;
    printf("\nEnter the number of furniture, that you want to delete:");
    scanf("%i",&index);
    if(index == 1){
        first = first->next;
    }
    else if(index == n){
        for(int i = 1;i<index-1;i++){
            c = c->next;
        }
        last = c;
        last->next = 0;
    }
    else{
        for(int i=1;i<index-1;i++){
            prev = prev->next;
        }
        c = prev->next;
        prev->next = c->next;
        c->next = 0;
    }
}
void insert_after(int n)
{
    int index;
    scanf("%i",&index);
    mylist *c;
    mylist *new_el;
    if(index == 1){
        c = new mylist;
        printf("    length = ");
        scanf("%i",&c->a.length);
        printf("    width = ");
        scanf("%i",&c->a.width);
        printf("    height = ");
        scanf("%i",&c->a.height);
        c->next = first;
        first = c;
        first = c;
    }



    //zdes;
    else if(index == n+1){
        new_el = first;
        c = new mylist;
        printf("    length = ");
        scanf("%i",&c->a.length);
        printf("    width = ");
        scanf("%i",&c->a.width);
        printf("    height = ");
        scanf("%i",&c->a.height);
        for(int i=1;i<index-1;i++){
            new_el = new_el->next;
        }
        c->next = new_el->next;
        new_el->next = c;
        last = c;
    }
    else{
        new_el = first;
        c = new mylist;
        printf("    length = ");
        scanf("%i",&c->a.length);
        printf("    width = ");
        scanf("%i",&c->a.width);
        printf("    height = ");
        scanf("%i",&c->a.height);
        for(int i=1;i<index-1;i++){
            new_el = new_el->next;
        }
        c->next = new_el->next;
        new_el->next = c;
    }

}
int main(){
    SetColor(15);
    int n=2,e=3,m=0;
    printf("Type number of furnitures:");scanf("%i",&n);
    int k,menuCase;
    printf("Enter the size of furnitures:\n");
    for(int i=0;i<n;i++){
        printf("%i furniture:\n",i+1);
        create_list(i);
    }
    struct charact* b;
    b->height = 10;
    (*b).length = 3;

Menu:
    printf("\nMenu:\n0)Exit\n1)Output struct\n2)Insert one element to struct\n3)Delete an element in the struct\n-->");
    scanf("%i",&menuCase);


    switch(menuCase){
    case 0:
        goto End;
        break;
    case 1:
        output_struct();
        goto Menu;
        break;
    case 2:
        insert_before(n);
        goto Menu;
        break;
    case 3:
        delEl(n);
        goto Menu;
        break;
    }
End:
    getche();

}
