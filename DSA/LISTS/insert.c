#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;

};
int main(){
    int n;
    scanf("%d",&n);
    struct Node * head =NULL;
    struct Node * temp=NULL;
    for(int i=0;i<n;i++){
        struct Node* new=malloc(sizeof(struct Node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head=new;
            temp=new;
        }
        else {
            temp->next=new;
            temp=new;
        }
        
    }
    temp=head;  
       
    struct Node* ins=malloc(sizeof(struct Node));
    scanf("%d",&ins->data);
    ins->next=temp;
    struct Node *ptr=ins;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    return 0;



    

}