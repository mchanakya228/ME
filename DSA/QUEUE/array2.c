#include<stdlib.h>
#include<stdio.h>

#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(front==(rear+1)%N){
        printf("\nQUEUE FULL\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if (front==-1&&rear==-1){
        printf("Nothing to delete");
    }
    else{
        printf("\nqueue that is going to be deleted =%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if (front==-1&&rear==-1){
        printf("Nothing to display");
    }
    else{
        int i=front;
        printf("QUEUE= ");
        while(1){
            
            printf("\n%d\n ",queue[i]);
            
            if(i==rear){
                break;
            }
            i=(i+1)%N;
    }


}
}
void peek(){
    if (front==-1&&rear==-1){
        printf("Nothing to delete");
    }
    else{
        printf("peek= %d ",queue[front]);
    }
}
int main(){
    enqueue(12);
    enqueue(123);
    enqueue(1);
    enqueue(13);
    enqueue(14);
    enqueue(23);
    display();
    dequeue();
    dequeue();
    enqueue(23);
    display();
    peek();


    return 0;
}