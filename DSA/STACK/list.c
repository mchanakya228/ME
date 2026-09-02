#include<stdlib.h>
#include<stdio.h>
struct node{
  int data;
  struct node*next;
};
struct node * top=NULL;
void push(){
    printf("enter data to push:");
    int n;
    scanf("%d",&n);
  struct node *new=malloc(sizeof(struct node));
  new->data=n;
  new->next=top;
  top=new;
  
}
void display(){
    struct node*ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    int i=1;
    while(i!=0){
          printf("\n PRESS: \n 0.EXIT\n 1.TO PUSH DATA\n 2.DISPLAY\n 3.POP\n 4.PEEK \n ");
         scanf("%d",&i);
        switch(i){
            case(1):push();
            break;
            case(2):display();
            break;
        }
    }
    return 0;
}