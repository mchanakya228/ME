#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node * head=NULL;
struct node* tail=NULL;
void insert(int x){
    struct node*new=malloc(sizeof(struct node));
     new->data=x;
        new->next=NULL;
    if(head==NULL&&tail==NULL){
        head=new;
        
        tail=new;

    }
    else{
        tail->next=new;
        tail=new;
    }
    
}
int length() {
    int count = 0;
    struct node *ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}
void position(int x,int n,int p){
    struct node * new=malloc(sizeof(struct node));
    new->data=n;
    if(x==1){
        new->next=head;
        head=new;
    }
    else if(x==p+1){
        tail->next=new;
        new->next=NULL;
        tail=new;
    }
    else{
        struct node* temp1=head;
        struct node* temp2=head;

        for(int i=1;i<x;i++){
            temp1=temp1->next;
            



        }
        new->next=temp1;
        for(int i=1;i<x-1;i++){
            temp2=temp2->next;
            



        }
        temp2->next=new;
    }

}
void delete(int x,int p){
    struct node* temp=head;
    if(head==NULL){
        printf("nothing to delete");
    }
    else if(x==1){
        head=head->next;
        free(temp);
        
    }
    else if(x==p){
        struct node*err=tail;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        tail=temp;
        free(err);

    }
    else{
        struct node * erri=head;
        for(int i=1;i<=x-1;i++){
            temp=temp->next;
        }
        for(int i=1;i<x+1;i++){
            erri=erri->next;
        }
        temp->next=erri;
    }
}
void display(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        struct node*ptr=head;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main(){
    insert(4);
    insert(123);
    insert(14322);
    display();
    int p=length();
    position(2,156,p);
    display();
    int q=length();
    delete(3,q);
    display();



    return 0;
}