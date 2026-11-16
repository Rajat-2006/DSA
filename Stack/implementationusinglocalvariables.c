#include<stdio.h>
#define MAX 5
void push(int stack[],int *top,int value){
    if(*top==MAX-1){
        printf("Stack overflow\n");
    }
    else{
        (*top)++;
        stack[*top]=value;
        printf("element inserted successfully\n");
    }
}

void pop(int stack[],int *top){
    if(*top==-1){
        printf("stack is empty\n");
    }
    else{
        int value=stack[*top];
        printf("Element deleted successfully: %d",value);
        (*top)--;
    }
}

void peek(int stack[],int *top){
    if(*top==-1){
        printf("stack is empty");
    }
    else{
        printf("top element: %d",stack[*top]);
    }
}

void display(int stack[],int *top){
    int i;
    if(*top==-1){
        printf("Stack is empty");
    }
    else{
        printf("stack elements: ");
        for(i=*top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}

int main(){
    int stack[MAX];
    int top=-1;
    int choice,value;
    while(1){
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push(stack,&top,value);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                peek(stack,&top);
                break;
            case 4:
                display(stack,&top);
                break;
            case 5:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice! ");
        }
    }
    return 0;
}