#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_Arr[MAX];
int top=-1;


void push(int data){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        top=top+1;
        stack_Arr[top]=data;
    }
}

int pop(){
    int value;
    if(top==-1){
        printf("UNDERFLOW\n");
        return -99;
    }
    else{
        top=top-1;
        value=stack_Arr[top];
        return value;
    }
}

void print(){
    if(top==-1){
        printf("Underflow\n");
        return;
    }
    for(int i=top; i>=0; i--){
        printf("%d ",stack_Arr[i]);
        printf("\n");
    }
}
int main(){
    int data;
    int extr;
    int choice=1;
    while(choice==1){
        printf("What Stack operation would u like to go with, 1-> PUSH, 2-> POP, 3->show: ");
        scanf("%d",&extr);
        switch(extr){
            case 1:{
                int no;
                printf("Enter the value u would like to push: ");
                scanf("%d",&no);
                push(no);
                break;
            }
            case 2:{
                data=pop();
                break;
            }
            case 3:{
                print();
                break;
            }
        }
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;
}