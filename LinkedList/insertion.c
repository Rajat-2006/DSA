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
//insert at beginning of a singly linked list
struct node *insertBeginning(struct node *head){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory allocation failed");
        return head;
    }
    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}

//insert at end of a singly linked list
struct node *insertEnd(struct node *head){
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory allocation failed");
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

//insert node at specific position in a singly linked list
struct node *insertSpecific(struct node *head){
    struct node *newnode,*temp;
    int pos,i;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("memory allocation failed");
        return head;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    printf("Enter position you want to insert: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("invalid position");
        free(newnode);
        return head;
    }
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return head;
    }
    temp=head;
    for(i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("invalid postion");
        free(newnode);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;

}

//displaying singly linked list
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
        printf("1.Create 2.Display 3.insertBeginning 4.insertEnd 5.insertSpecific 6.Exit\n");
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
                head=insertBeginning(head);
                break;
            case 4:
                head=insertEnd(head);
                break;
            case 5:
                head=insertSpecific(head);
                break;
            case 6:
                printf("exiting program..");
                exit(0);
            default:
                printf("Invalid choice! ");
        }
    }while(choice!=6);
    return 0;
}
