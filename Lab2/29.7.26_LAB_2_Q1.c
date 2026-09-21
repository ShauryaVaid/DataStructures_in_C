#include<stdio.h>
/*WAP to create a 1-D array of n elements 
and perform the following menu based operations using function.*/
int insert(int *arr, int len){
    //a. insert a given element at specific position.
    printf("---------------insert a given element---------------\n");
    int pos,ele;
    printf("Enter specific position to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element to insert: ");
    scanf("%d",&ele);
    
    for(int i=len-1; i>=pos; i--){
        arr[i+1]=arr[i];

    }
    arr[pos] = ele;
    len++;
}
int delete(int *arr, int len){
    //b. delete an element from a specific position of the array.
    printf("---------------delete an element---------------\n");
    int pos;
    printf("Enter specific position to delete the element: ");
    scanf("%d",&pos);
    for(int i=pos; i<len-1; i++){
        arr[i]=arr[i+1];
    }
    return len - 1;
}
int linear_search(int *arr, int len){
    //c. linear search to search an element
    printf("---------------Linear search---------------\n");
    int key,m=0;
    printf("Enter the number for which u want to start linearSearch optionnn:");
    scanf("%d",&key);
    for(int i=0; i<len; i++){
        if(arr[i]==key){
            printf("FOUND THE ELEMENT AT INDEX: %d\n",i);
            m++;
        }
    }
    if(m==0){
            printf("NOT FOUND");
        }
}
int Final_Karnama(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("%d ,",arr[i]);
    }
}

int main(){
    int n,q;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    //int len= sizeof(arr)/sizeof(int);
    printf("---------------Elements for the array---------------\n");
    for(int i=0; i<n; i++){
        printf("Enter the %d element: \n",i);
        scanf("%d",&arr[i]);
    }
    printf("---------------***MENU***---------------\n");
    //options badhiya rahenge idhar
    printf("Choose from the list: 1-Insert, 2-Delete, 3-linear search, 4-Traverse");
    scanf("%d",&q);
    if(q==1){
        insert(arr,n);
    }
    else if(q==2){
        n=delete(arr,n);
    }
    else if(q==3){
        linear_search(arr,n);
    }
    else if(q==4){
        Final_Karnama(arr,n);
    }

    //IRRESPECTIVE OF WHAT U CHOOSE TO CONFIRM HERE U GO:
    printf("---------------check below if it worked!---------------\n");
    Final_Karnama(arr,n);
}