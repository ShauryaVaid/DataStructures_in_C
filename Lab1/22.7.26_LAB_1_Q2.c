#include<stdio.h>
#include<math.h>

int primii(int valuee){
    if(valuee<=1){return 0;}
    for(int i=2; i<=sqrt(valuee); i++){
        if(valuee%i==0){
            return 0;
        }
    }
    return 1;
}


int sumofprimee(int *arr, int n){
    int summ=0;
    for(int i=0; i<n; i++){
        if(primii(arr[i])){
            summ+=arr[i];
        }
    }
    return summ;
}


int main(){
    int n;
    printf("Enter size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Sum= %d",sumofprimee(arr,n));
}