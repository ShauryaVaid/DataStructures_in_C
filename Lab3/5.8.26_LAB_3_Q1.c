//WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include<stdio.h>
typedef struct sparse{
    int r; //row
    int c; //col
    int val; //valuee
}sparse;
//sparse matrix
int main(){
    int a[10][10];
    int row,col,k;
    int nz=0;
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&row,&col);
    printf("Enter matrix elements: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                nz++;
            }
        }
    }
    sparse st[nz],tr[nz];
    k=0;
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                st[k].r=i;
                st[k].c=j;
                st[k].val=a[i][j];
                k++;
            }
        }
    }
    k=0;
    for(int j=0; j<col; j++){
        for(int i=0; i<nz; i++){
            if(st[i].c==j){
                tr[k].r=st[i].c;
                tr[k].c=st[i].r;
                tr[k].val=st[i].val;
                k++;
            }
        }
    }
    printf("\nTranspose in 3-tuple format: \n");
    printf("Row \t Column \t Value \n");
    for (int i = 0; i < nz; i++) {
        printf("%d \t %d \t\t %d \n", tr[i].r, tr[i].c, tr[i].val);
    }

    return 0;
}