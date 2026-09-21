//Write a menu driven program to create a structure to represent complex number and perform the following operation using function :
//1. addition of two complex number  (call by value)
//2. multiplication of two complex number (call by address)
#include<stdio.h>

typedef struct complexx{
    int real;
    int imaginary;
}complexx;

int add(complexx c1, complexx c2){
    int real_part= c1.real+c2.real;
    int imaginary_part= c1.imaginary+c2.imaginary;
    printf("Sum=%d+%di",real_part,imaginary_part);
}

int mul(complexx *c1, complexx *c2){
    int real_part = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    int imag_part = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    printf("Product = %d + %di\n", real_part, imag_part);
}

int main(){
    int a;
    complexx c1,c2;
    printf("Enter complex number 1:");
    scanf("%d%d",&c1.real,&c1.imaginary);
    printf("Enter complex number 2:");
    scanf("%d%d",&c2.real,&c2.imaginary);
    
    printf("MENU\n1. addition\n2. multiplication\nEnter your choice:");
    scanf("%d",&a);
    if(a==1){
        add(c1,c2);
    }
    else if(a==2){
        mul(&c1,&c2);
    }
    else{
        printf("Wear ur specs!");
    }
    return 0;
}
