#include<stdio.h>
#include<stdlib.h>

typedef struct terms{
    int coeff;
    int pow;
}terms;

terms *add(terms P1[], terms P2[], int n1, int n2, int *n3){
    terms *P3 = (terms*)malloc(sizeof(terms)*(n1+n2));
    //terms P3[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(P1[i].pow==P2[j].pow){
            P3[k].coeff=P1[i].coeff+P2[j].coeff;
            P3[k].pow=P1[i].pow;
            i++;j++;k++;
        }
        else if(P1[i].pow>P2[j].pow){
            P3[k].coeff=P1[i].coeff;
            P3[k].pow=P1[i].pow;
            i++;k++;
        }
        else if(P1[i].pow<P2[j].pow){
            P3[k].coeff=P2[j].coeff;
            P3[k].pow=P2[j].pow;
            j++;k++;
        }
    }
    while (i < n1) {
        P3[k++] = P1[i++];
    }
    while (j < n2) {
        P3[k++] = P2[j++];
    }
    *n3=k;
    return P3;
}

int main(){
    int c,p,n1,n2;
    printf("Enter no. of terms: ");
    scanf("%d",&n1);

    terms P1[n1];

    printf("Enter coeff and power of each terms: \n");
    for(int i=0; i<n1; i++){
        scanf("%d",&P1[i].coeff);
        scanf("%d",&P1[i].pow);
    }

    printf("Enter no. of terms: ");
    scanf("%d",&n2);

    terms P2[n2];

    printf("Enter coeff and power of each terms: \n");
    for(int i=0; i<n2; i++){
        scanf("%d",&P2[i].coeff);
        scanf("%d",&P2[i].pow);
    }
    int n3=0;
    terms *P3 = add(P1, P2, n1, n2, &n3);

    //display:-
    for(int i=0; i<n1; i++){
        if(i!=n1-1){
            printf("%dx^%d+ ",P1[i].coeff,P1[i].pow);
        }
        else{
            printf("%dx^%d",P1[i].coeff,P1[i].pow);
        }
    }
    printf("\n");

    //display:-
    for(int i=0; i<n2; i++){
        if(i!=n1-1){
            printf("%dx^%d+ ",P2[i].coeff,P2[i].pow);
        }
        else{
            printf("%dx^%d",P2[i].coeff,P2[i].pow);
        }
    }
    printf("\n");
    printf("FINAL ADDITION:-\n");
    for(int i=0; i<n3; i++){
        if(i!=n3-1){
            printf("%dx^%d+ ",P3[i].coeff,P3[i].pow);
        }
        else{
            printf("%dx^%d",P3[i].coeff,P3[i].pow);
        }
    }
    printf("\n");
    return 0;
}