#include<stdio.h>
//
typedef struct sparse{
    int r;
    int c; //these r,c,val form is called 3 tupple form.
    int val;
}sparse;

int main(){
    int row,col,k;
    int nz=0; //non_zero elements.
    printf("Enter the size of the matrix row, col: ");
    scanf("%d%d",&row,&col);
    int a[row][col];
    printf("Enter the elemnents of the matrix: ");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d",&a[i][j]);       //this is just the normal matrix
            if(a[i][j]!=0){
                nz++;
            }
        }
    }
    sparse st[nz];
    k=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(a[i][j]!=0){
                st[k].r=i;             //this is sparse matrix.
                st[k].c=j;
                st[k].val=a[i][j];
                k++;
            }
        }
    }
    k=0;
    //for transpose:
    sparse tr[nz];
    for(int j=0; j<col; j++){
        for(int i=0; i<nz; i++){
            if(st[i].c==j){
                tr[k].r=st[i].c;      //this transposes to a new matrix tr[nz].
                tr[k].c=st[i].r;
                tr[k].val=st[i].val;
                k++;
            }
        }
    }
    printf("----------TRANSPOSE_FINISHED----------");
    //matrix addition
    int nz1=0,nz2=0;
    int row1,row2,col1,col2;
    printf("Enter the size of the matrix_1 row, col: ");
    scanf("%d%d",&row1,&col1);
    int b[row1][col1];
    printf("Enter the elemnents of the first matrix: ");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            scanf("%d",&b[i][j]);       
            if(b[i][j]!=0){
                nz1++;
            }
        }
    }
    sparse mat1[nz1];
    printf("Enter the size of the matrix_2 row, col: ");
    scanf("%d%d",&row2,&col2);
    int c[row2][col2];
    printf("Enter the elemnents of the second matrix: ");
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            scanf("%d",&c[i][j]);       
            if(c[i][j]!=0){
                nz2++;
            }
        }
    }
    sparse mat2[nz2];
    //now conversion to sparse matrix.
    k=0;
    for(int i=0; i<row1;i++){
        for(int j=0; j<col1; j++){
            if(b[i][j]!=0){
                mat1[k].r=i;
                mat1[k].c=j;
                mat1[k].val=b[i][j];
                k++;
            }
        }
    }
    k=0;
    for(int i=0; i<row2;i++){
        for(int j=0; j<col2; j++){
            if(c[i][j]!=0){
                mat2[k].r=i;
                mat2[k].c=j;
                mat2[k].val=c[i][j];
                k++;
            }
        }
    }
    sparse mat3[nz1*nz2];
    

}