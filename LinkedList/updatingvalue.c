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

//updating old value
void update(struct node *head){
    struct node *temp;
    int oldValue,newValue;
    printf("Enter old value: ");
    scanf("%d",&oldValue);
    temp=head;
    while(temp!=NULL){
        if(temp->data==oldValue){
            printf("Enter new value: ");
            scanf("%d",&newValue);
            temp->data=newValue;
            printf("Value updated successfully");
            return;
        }
        temp=temp->next;
    }
    printf("Element not found");
}
int main(){
    struct node *head=NULL;
    int choice;
    do{
        printf("1.Create 2.Display 3.update 4.Exit\n");
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
                update(head);
                break;
            case 4:
                printf("exiting program..");
                exit(0);
            default:
                printf("Invalid choice! ");
        }
    }while(choice!=4);
}