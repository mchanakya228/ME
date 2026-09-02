#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head =NULL;
struct node * temp =NULL;
void display(){
    struct node *ptr=head;
    if(head==NULL){
        printf("List is empty");
    }
    else{
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    }
}

void ins_beg(){
    struct node * ins = malloc(sizeof(struct node));
    printf("enter Extra term: ");
    scanf("%d",&ins->data);
    ins->next=head;
    head=ins;
    display();
}
void del_last(){
    if(head==0){
        printf("list empty");
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        display();
        return;

        
    }
     struct node * em=head;
    
    while(em->next->next!=NULL){
        em=em->next;
        
    }
   
    struct node* del=em->next;
    em->next=NULL;
    
    free(del);
    display();


}
void ins_last(){
    struct node * in=malloc(sizeof(struct node));
    printf("enter extra term:");
    scanf("%d",&in->data);
    in->next=NULL;
    if(head==0){
        head=in;
    }
    else{ 
    struct node * em=head;
    while(em->next!=NULL){
        em=em->next;
    }
    em->next=in;
    em=in;
    display();
    }

}
void del_beg(){
     if(head==0){
        printf("List empty");
        return;
    }
    else{ 
    struct node * del=head;
    head=head->next;
    free(del);
    display();
    }
}

    

int main(){
    int n;
    printf("Enter no of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct node * new=malloc(sizeof(struct node));
        printf("enter %d term:",i+1);
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==0){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
    }
    int choice=1;
    
    
    while(choice!=0){
        printf("\n0.stop\n 1.insert begin\n2.insert last\n3.delete begin\n4.delete last\n");
        scanf("%d",&choice);
     if(choice==1){
        ins_beg();
     }
     else if(choice==2){
        ins_last();

     }
     else if(choice==3){
        del_beg();

     }
     else if(choice==4){
        del_last();

     }
     
      

    
}
  return 0;
}
