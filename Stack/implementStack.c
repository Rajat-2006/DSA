#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;
void push(int value){
    if(top==MAX-1){
        printf("stack overflow\n");
    }
    else{
        top++;
        stack[top]=value;
    }
}

void pop(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        int value=stack[top];
        top--;
        printf("Deleted element: %d",value);
    }
}

void peek(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("Top element is: %d",stack[top]);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack element: ");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main(){
    int choice,value;
    while(1){
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice! please try again");
        }  
    }
    return 0;
}