#include<stdio.h>
#include<stdlib.h>
//1 WAP to find out the smallest and largest element stored in an array of n integers.
void largest(int *arr, int n){
    int lar;
    for(int i=0; i<=n; i++){
        
        for(int j=0; j<=n; j++){     //TIME COMPLEXITY 0(N^2)
            
            if(arr[i]>arr[j]){
                lar=arr[i];
            }
        }
    }
    printf("largest: %d\n", lar);
    //return lar;
}
void smallest(int *arr, int n){
    int smal;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){     //TIME COMPLEXITY 0(N^2)
            if(arr[i]<arr[j]){
                smal=arr[i];
            }
        }
    }
    printf("smallest: %d\n", smal);
    //return smal;
}

//Write a program to read two numbers and compare the numbers using function call by address.
void compare(int *a, int *b) {
    if (*a > *b) {
        printf("%d is greater than %d\n", *a, *b);
    } 
    else if (*a < *b) {
        printf("%d is smaller than %d\n", *a, *b);
    } 
    else {
        printf("Both numbers are same\n");
    }
}

//Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all 
//the prime elements of the array using function and de-allocate the memory of the array after its use.
int dma(int n){
    int *v=(int *)malloc(n*sizeof(int));
    
}
int main(){
    int arr[5]={5,4,3,2,1};
    int n= sizeof(arr)/sizeof(int);
    int a,b;
    /*printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    Compare(&a, &b);*/
    
    //MALLOC
    /*int *k=(int *)malloc(4);
    printf("Enter the number: ");
    scanf("%d",k);
    printf("%d",*k);*/
    

    /*unsigned char c=256;
    printf("%u \n", c);
    printf("%d",c);*/
    //largest(arr, n);
    //smallest(arr, n);
}
