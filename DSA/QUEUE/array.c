#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==N-1){
        printf("Overflow\n");
    }
    else if(front==-1&&rear==-1){
        front++;
        rear++;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
    

}
void display(){
    if(front==-1&&rear==-1){
        printf("EMPTY QUEUE");
    }

    else{
        printf("\nQUEUE= ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Nothing to delete");
    }
    else if (front==rear){
        front=rear=-1;
    }
    else{
        printf("\nqueue going to be delted:%d ",queue[front]);
        front++;
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("nothing to peek");
    }
    else{
        printf("\npeek= %d ",queue[front]);
    }
}
int main(){
     enqueue(24);
     enqueue(12);
     enqueue(76);
     display();
     peek();
     dequeue();
     display();
     peek();


    return 0;
}