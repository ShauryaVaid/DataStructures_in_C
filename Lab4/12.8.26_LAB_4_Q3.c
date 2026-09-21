/*4.3 Write a program to represent the polynomial equation of single variable using single linked list and perform the
addition of two polynomial equations.
Sample Input:
Polynomial-1:
Enter the Maximum power of x: 2
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1: 3

Enter the coefficient of degree 0:2
Polynomial-2:
Enter the Maximum power of x: 3
Enter the coefficient of degree 3: 5
Enter the coefficient of degree 2: 4
Enter the coefficient of degree 1:6
Enter the coefficient of degree 0:10

Sample Output:
Sum: 5x^3+8x^2+9x^1+12x^0.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct poly{
    int coeff;
    int power;
    struct poly *next;
}poly;

int main(){
    poly *start;
    poly *prev; 
    poly *curr;
    int n;
    printf("Enter maximum degree of x: ");
    scanf("%d",&n);
    printf("Enter Polynomial-1 from lowest degree to highest degree:  (Hint: 4+2x+3x^2)\n");
    for(int i=0;i<n;i++){
        poly *temp= malloc(sizeof(poly));
        scanf("%d%d",&temp->coeff,&temp->power);
        temp->next=NULL;
        if(start==NULL){
            start=temp;
            prev=temp;
            curr=temp;
        }
        else{
            curr->next=
            
        }
    }

}