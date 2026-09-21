//WAP to perform addition of two given sparse matrix in 3–tuple format.
#include<stdio.h>

typedef struct sparse{
    int r;
    int c;
    int val;
}sparse;

int main(){
    int a[10][10],b[10][10];
    int i,row,col,j,k,nz1=0,nz2=0;
    printf("Enter the row and col of the matrix: ");
    scanf("%d%d",&row,&col);

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d",&b[i][j]);
        }
    }
    sparse st[100];

    k=0;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            int sum=a[i][j]+b[i][j];
            if(sum!=0){
                st[k].r=i;
                st[k].c=j;
                st[k].val=sum;
                k++;
            }
        }
    }

    printf("\nAddition of two sparse matrix in 3-tuple format: \n");
    printf("Row \t Column \t Value \n");
    for (int i = 0; i < k; i++) {
        printf("%d \t %d \t\t %d \n", st[i].r, st[i].c, st[i].val);
    }
    return 0;
}