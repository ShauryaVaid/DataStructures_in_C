#include<stdio.h>
/*int main(){
    int a[8]={13,10,2,3,7,8,6,11};
    int n = sizeof(a)/sizeof(int);
    for(int i=0; i<n; i++){
        if(a[i]%2==0){
            a[i]=-99;
        }
        else{
            continue;
        }
    }

    for(int i=0; i<n; i++){
        if(a[i]!=(-99)){
            printf("%d, ",a[i]);
        }
        ;
    }
}
*/

/*void fun(int a[], int n, int i){
    if(i>=n/2){
        return;
    }

    int temp= a[i];
    a[i]=a[n-1-i];
    a[n-1-i]=temp;

    fun(a,n,i+1);
}
int main(){
    int i=0;
    int a[8]={1,2,3,4,5,6,7,8};
    int n = sizeof(a)/sizeof(int);
    fun(a,n,i);
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}*/

typedef struct sparse{
    int r;
    int c;
    int val;
}sparse;
int main(){
    int row,col,k;
    int nz=0;
    printf("Enter row,col: ");
    scanf("%d%d",&row,&col);
    int a[row][col];
    printf("enter elements of matrix: ");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                nz++;
            }
        }
    }
    sparse st[nz];
    k=0;
    for(int i=0;i<row;i++){
        for(int j=0; j<col; j++){
            if(a[i][j]!=0){
                st[k].r=i;
                st[k].c=j;
                st[k].val=a[i][j];
                k++;
            }
        }
    }
}