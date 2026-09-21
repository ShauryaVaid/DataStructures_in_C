#include<stdio.h>

typedef struct sparse{
    int r;
    int c;
    int val;
}sparse;

int main(){
    int a[10][10];
    int k,i,j,row,col,nz=0;
    printf("Enter row and column of the matrix: ");
    scanf("%d%d",&row,&col);
    printf("Enter elements: \n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d",&a[i][j]);
        }
        if(a[i][j]!=0){
            nz++;
        }
    }

    sparse st[nz],tr[nz];

    k=0;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(a[i][j]!=0){
                st[k].r=i;
                st[k].c=j;
                st[k].val=a[i][j];
                k++;
            }
        }
    }

    k=0;
    for(j=0; j<col; j++){
        for(i=0; i<nz; i++){
            if(st[i].c==j){
                tr[k].r=j;
                tr[k].c=i;
                tr[k].val=a[i][j];
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
