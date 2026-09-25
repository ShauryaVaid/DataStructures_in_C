#include<stdio.h>
/*6.1 Write a menu driven program to create a stack using array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/
int top=-1;
void push(int stack_Arr[],int size){
    if(top==size-1){
        printf("Overflow\n");
        return;
    }
    int val;
    printf("Enter the value to push: ");
    scanf("%d",&val);
    top+=1; 
    stack_Arr[top]=val;
}

int pop(int stack_Arr[]){
    int val;
    if(top==-1){
        printf("Underflow\n");
        return -999999;
    }
    else{
        val=stack_Arr[top];
        top-=1;
        return val;
    }
}

void display(int stack_Arr[],int size){
    if(top==-1){
        printf("Underflow\n");
        return;
    }
    for(int i=top; i>=0; i--){
        printf("%d-> ",stack_Arr[i]);
    
    }
    printf("\n");
    return;
}

void check_stackempty(int stack_Arr[]){
    if(top==-1){
        printf("STACK EMPTY\n");
        return;
    }
    else{
        printf("STACK NOT EMPTY\n");
        return;
    }
}

void check_stackfull(int stack_Arr[],int size){
    if(top==size-1){
        printf("STACK FULL\n");
        return;
    }
    else{
        printf("STACK NOT FULL\n");
        return;
    }
}

int main(){
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    int stack_Arr[size];
    int data;
    int extr;
    int choice=1;
    while(choice==1){
        printf("What Stack operation would u like to go with,\n 1-> PUSH, 2-> POP, 3->show, 4->check stack is empty or not, 5->check stack is full or not: ");
        scanf("%d",&extr);
        switch(extr){
            case 1:{
                push(stack_Arr,size);
                break;
            }
            case 2:{
                data=pop(stack_Arr);
                printf("POPED-> %d",data);
                break;
            }
            case 3:{
                display(stack_Arr,size);
                break;
            }
            case 4:{
                check_stackempty(stack_Arr);
                break;
            }
            case 5:{
                check_stackfull(stack_Arr,size);
                break;
            }
        }
        printf("\n");
        printf("Enter 1 if want to continue else any key: ");
        scanf("%d",&choice);
    }
    return 0;
}