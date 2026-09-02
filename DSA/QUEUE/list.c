#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};
struct node * front=NULL;
struct node* rear=NULL;
void enqueue(int x){
    if(front==NULL&&rear==NULL){
    struct node* new=malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    front=new;
    rear=new;
}
   else{
    struct node*new=malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    rear->next=new;
    rear=new;
    
   }
}
void display(){
    struct node * ptr=front;
    printf("\nQUEUE= ");
    while(ptr!=NULL){
        printf("\n%d ",ptr->data);
        ptr=ptr->next;
    }

}
void dequeue(){
    if(front==NULL&&rear==NULL){
        printf("\nnothing to delete");
    }
    else if (front==rear){
        front=NULL;
        rear=NULL;
        printf("\nlist is empty");
    }
    else{
    struct node* temp=malloc(sizeof(struct node));
    temp=front;
    front=front->next;
    free(temp);
}
}
void peek(){
     if(front==NULL&&rear==NULL){
        printf("nothing to peek");
    }
    else{
        printf("\npeek= %d ",front->data);
    }
}


int main(){
    enqueue(24);
    enqueue(12);
    display();
    dequeue();
    display();
    peek();
    dequeue();
    display();
    peek();

    return 0;
}