#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head=NULL;
struct node * temp=NULL;
void display(){
    struct node * ptr=head;
    if(head==NULL){
        printf("list is empty");

    }
    else{
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}
} 
int ins(){
    printf("Enter position:");
    int i;
    scanf("%d",&i);
    printf("extra term");
    int n;
    scanf("%d",&n);
    struct node * new=malloc(sizeof(struct node));
    new->data=n;
    new->next=NULL;
    if(i==1){
        new->next=head;
        head=new;
        return 0;
    }
    else{
      for(int i=0;i<i-1;i++){
        if(temp==NULL){
            printf("invalid");
            free(new);
            return 0;
        }
        temp=temp->next;

      }
    if(temp=NULL){
       printf("Invalid");
       free(new);
       return 0;

    }
    new->next=temp->next;
    temp->next=new;
 return 0;
} }
int main(){
    printf("enter # of terms:");
    int n;
    scanf("%d",&n);
    
    for (int i=0;i<n;i++){
        struct node * new=malloc(sizeof(struct node));
        printf("enter %d item:",i+1);
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==0){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
        
    }
    temp=head;
    display();
    ins();
    printf("result");
    display();
    return 0;
}