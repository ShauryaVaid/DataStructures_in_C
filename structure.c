#include<stdio.h>
#include<stdlib.h>
typedef struct book{
    int id;
    char title[50];
    int price;
}book;
void freeeee(void *a){
    free(a);
}
int main(){
    book *b1 = (book*) malloc(sizeof(book));
    b1->id=20;
    printf("%d",b1->id);
    freeeee(b1);
}

