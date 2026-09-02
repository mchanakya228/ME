#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node * next;
};
 
struct node * head ;
struct node * tail ;

void create(){

struct node * new ;

int choice=1 ;
head = tail = 0;
while(choice){
new = (struct node *)malloc(sizeof(struct node));
printf("Enter data\n");
scanf("%d",&new->data);
new->next=0;
struct node* temp;
if(head==0){
    head = new ;
}
else{
   tail->next=new;
}
tail=new ;
printf("Do you want to add another node (0/1)\n");
scanf("%d",&choice);

}
}

void ins_beg(){
    struct node* new ;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data\n");
scanf("%d",&new->data);
new ->next= 0;
if(head==0){
    head = tail = new;
}
else{
new->next=head;
head = new;

}
}

void del_beg(){
    struct node * temp=head;
    if(head==0){
        printf("List is empty\n");
    }
    else if(head == tail){
head = tail =0;
    }
    else{
        head = head ->next;
    }
    free(temp);
}
void ins_end(){
    struct node*new ;
     new = (struct node *)malloc(sizeof(struct node));
     printf("Enter data\n");
scanf("%d",&new->data);
new ->next= 0;
if(head==0){
    head = new;
}
else{
   tail->next=new;
   tail=new;
}
}
void del_end(){
    struct node * temp=head;
    if(head==0){
        printf("List is empty\n");

    }
    else if(head == tail){
        head = tail = 0;
        free(temp);
    }
    else{
        while(temp->next!=tail){
            temp =temp->next;
        }
        temp->next=0;
        free(tail);
        tail= temp;
        
    }
}

void display(){
    struct node * temp =head ;
    if (head ==0){
        printf("List is empty\n");
    }
    else{
        while (temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void main(){
    create();
   int i,j=1;
   while(j){
    printf("enter your choice \n 1 :insert at beginning\n 2: delete at beginning\n 3 :display\n 4 :insert at end\n 5 :delete at end\n");
    scanf("%d",&i);

    switch (i)
    {
    case 1:ins_beg();
        break;
    case 2:del_beg();
    break;
    case 3:display();
    break;
    case 4:ins_end();
    break;
    case 5:del_end();
    break;
    default:
    printf("Invalid Choice");
        break;
    }
    printf("Do you want to do another operation (0/1)\n");
    scanf("%d",&j);
}

}