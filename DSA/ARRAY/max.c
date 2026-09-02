#include<stdio.h>
void read(int arr[],int n){

    for (int i=0;i<n;i++){
        printf( " enter %d term = ",i+1 );
        scanf("%d",&arr[i]);
        

    }
}
int maxi(int arr[],int n){
    int maxim=arr[0];
    for(int i=1;i<n;i++){
        if(maxim<arr[i]){
            maxim=arr[i];
        }
        
    }
    return maxim;

}
void reverse(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        printf("reversed array=%d ",arr[i]);

    }
}   

int main(){
    int n;
    printf("ENter no.of terms: ");
    scanf("%d",&n);
    int arr[n];
    read(arr,n);
    printf("max= %d\n ",maxi(arr,n));
    reverse(arr,n);



    return 0;
}