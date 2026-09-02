#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
int main (){
    struct Node * head =NULL;
    struct Node * temp =NULL;

    int n;
    printf("Number of integers: ");
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        struct Node * new= malloc(sizeof(struct Node));
        printf("DATA: ");
        scanf("%d ",&new->data);
        new->next=NULL;
        if (head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;


        
    }

}