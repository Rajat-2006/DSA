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

//delete node from beginning of singly linked list
struct node *deleteBeginning(struct node *head){
    struct node *temp;
    if(head==NULL){
        printf("linked list is empty");
        return head;
    }
    temp=head;
    head=head->next;
    free(temp);
    return head;
}

//delete node from end of singly linked list
struct node *deleteEnd(struct node *head){
    struct node *temp,*prev;
    if(head==NULL){
        printf("linked list is empty");
        return head;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return head;
}

//delete from specific position
struct node *deleteSpecific(struct node *head){
    struct node *prev,*temp;
    int pos;
    if(head==NULL){
        printf("Linked list empty");
        return head;
    }
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<=0){
        printf("invalid position");
        return head;
    }
    if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    prev=head;
    for(int i=1;i<pos-1 && prev!=NULL;i++){
        prev=prev->next;
    }
    if(prev==NULL || prev->next==NULL){
        printf("invalid position");
        return head;
    }
    temp=prev->next;
    prev->next=temp->next;
    free(temp);
    return head;
}

//displaying linked list
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
        printf("1.Create 2.Display 3.deleteBeginning 4.deleteEnd 5.deleteSpecific 6.Exit\n");
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
                head=deleteBeginning(head);
                break;
            case 4:
                head=deleteEnd(head);
                break;
            case 5:
                head=deleteSpecific(head);
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
