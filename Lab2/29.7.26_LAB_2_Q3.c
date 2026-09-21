//WAP to represent a given sparse matrix in 3-tuple format using 2-D array. 
#include<stdio.h>
typedef struct sparse{
    int r; //row
    int c; //column
    int val; //value
}sparse;
//sparse matrix
int main(){
    int i,j,k;
    int a[4][4]={{1,0,3,4},
                    {0,0,5,6},
                    {4,0,0,6},
                    {7,8,0,0}};
    int nz=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(a[i][j]!=0){nz++;
            }
        }
    }

    sparse st[nz];
    k=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(a[i][j]!=0){
                st[k].r=i;
                st[k].c=j;
                st[k].val=a[i][j];
                k++;
            }
        }
    }
    
    printf("Row\tCol\tValue\n");
    for (i = 0; i < nz; i++) {
        printf("%d\t%d\t%d\n", st[i].r, st[i].c, st[i].val);
    }

    return 0;
    
}



