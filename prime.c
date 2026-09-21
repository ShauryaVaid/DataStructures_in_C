#include<stdio.h>
#include<math.h>
int prime(int n){
    if(n<=1){return 0;}
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Check if madeby LoganPaul! or not\n");
    printf("Enter the number for which u would like to run the search: ");
    scanf("%d",&n);
    int v = prime(n);
    if(v!=0){
        printf("U get a PRIME by LoganPaul");
    }
    else{
        printf("no Prime today..ask KSI;) ");
    }
}