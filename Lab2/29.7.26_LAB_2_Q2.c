/*2.2 Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/
#include<stdio.h>
int func(int n, int m, int arr[][m]){
    /*//to check the final matrix.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
    //no. of nonzero elements
    int nonzero=0;
    printf("Upper triangular matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=i+1; j<m; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]!=0){
                nonzero++;
            }
        }
    }
    return nonzero;


}
int main(){
    //int arr[3][3]={{1,2,3},{0,5,6},{7,8,9}};
    int n,m;
    printf("Enter size of the square matrix: ");
    scanf("%d",&n);
    m=n;
    printf("Enter elements of the matrix: \n");
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Nonzero elements : %d",func(n, m, arr));
    return 0;
}