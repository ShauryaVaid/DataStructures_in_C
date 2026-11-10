#include<stdio.h>
int main(){
    int v;
    int e;
    scanf("%d%d",&v,&e);
    int adjmat[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjmat[i][j]=0;
        }
    }
    int v1,v2;
    for(int i=0;i<e;i++){
        scanf("%d%d",&v1,&v2);
        adjmat[v1-1][v2-1]=1;
        adjmat[v2-1][v1-1]=1;
    }
}