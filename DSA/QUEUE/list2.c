#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int x){
    if(front==NULL&&rear==NULL){
    struct node *new=malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    front=new;
    rear=new;
}
    else {
           struct node *new=malloc(sizeof(struct node));
    new->data=x;
    new->next=front;
    rear->next=new;
    rear=new;
    }
}

void display(){
 
    if (front==NULL&&rear==NULL){
        printf("Nothing to display");
    }  
    else{
        struct node*ptr=front;
        printf("QUEUE= ");
       do{

            printf("%d ", ptr->data);

            ptr = ptr->next;

        }while(ptr != front);

    }
}
void dequeue(){
       if (front==NULL&&rear==NULL){
        printf("Nothing to display");
    }  
    else if (front==rear){
        front=NULL;
        rear=NULL;
        printf("empty");
    }
    else{
        printf("\ndeleted= %d\n ",front->data);
        struct node *temp=front;
        front=front->next;
        rear->next=front;
        free(temp);

    }

}
void peek(){
    if(front==NULL&&rear==NULL){
        printf("nothing to peek");
    }
    else{
        printf("\n peek= %d ",front->data);
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    display();
    peek();
    return 0;
}
