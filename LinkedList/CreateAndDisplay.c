#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head){
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory allocation failed!");
        return head;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
void display(struct node *head){
    struct node *temp;
    if(head==NULL){
        printf("Linked list empty");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head=NULL;
    int choice;
    do{
        printf("1.Create 2.Display 3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                head=create(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("exiting program..");
                exit(0);
            default:
                printf("Invalid choice! ");
        }
    }while(choice!=3);
}