#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node* head =NULL;
struct node * temp=NULL;
void display(){
    struct node* ptr=head;
    if(head==NULL){
        printf("UNDERFLOW");
    }
    else{
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
}

void push(){
    int i;
    printf("Enter term to push");
    scanf("%d",i);
    struct node * new =malloc(sizeof(struct node));
    new->data=i;
    new->next=temp;
    head=new;
    temp=new;
    display();

}


int main(){
  int o=1;
  while(o!=0){
    printf("\n0.EXIT\n1.PUSH\n2.DISPLAY\n");
    scanf("%d",o);
    switch(o){
        case(1):push();
        break;
        case(2) :display();
        break;
        default:
        printf("INVALID");
    }
  }


    return 0;
}

