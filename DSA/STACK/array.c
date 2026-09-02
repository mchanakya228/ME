#include<stdlib.h>
#include<stdio.h>
#define N 10
  int top =-1;
 int stack[N];
void push(){
    int n;
   printf("enter data to push :");  
   
   scanf("%d",&n);
    top++;
   if(top!=N){
     stack[top]=n;
   }
   
    else{
    
     printf("INVALID");
     
   
   }
} 
void display(){
    int i=top;
    if(top==-1){
        printf("Invalid");
        return;

    }
    
    else{
        while(i!=-1){
            printf("%d ",stack[i]);
            i--;
            
        }
    }

}
void pop(){
    if(top==-1){
        printf("invalid");
    }
    printf("%d ",stack[top]);
    top--; 
}
void peek(){
     if(top==-1){
        printf("invalid");
        return;
    }
    else{
    printf("%d",stack[top]);
}
}

int main(){
 int ch=1;

 while(ch!=0){
     printf("\n PRESS: \n 0.EXIT\n 1.TO PUSH DATA\n 2.DISPLAY\n 3.POP\n 4.PEEK \n ");
 scanf("%d",&ch);
    switch(ch){
     
        
  case(1):
    push();
    break;
   case(2): display();
   break;
   case(3):pop();
   break;
   case(4):peek();
   break;
   default: printf("invalid");
    }
}  
        
    
    return 0;

}