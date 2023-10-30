#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;

};

struct node*tail;

void createCLL()
{
    struct node*newnode;
    int choice=1;

    while(choice)
    {
        newnode=malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        tail==NULL;

        if(tail==NULL)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("do you want to continue\n");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node*ptr;
    ptr=tail->next;

    while(ptr->next!=tail->next)
    {
        printf("%d-->",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}

void reverse()
{
    struct node*current,*prev,*nextnode;
    current=tail->next;
    nextnode=current->next;

    while(current!=tail)
    {
        prev=current;
        current=nextnode;
        nextnode=current->next;
        current->next=prev;
    }
    nextnode->next=tail;
    tail=nextnode;

}

void addAtBeg()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert at beginning\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL:
    newnode->prev=NULL;

    if(head==NULL)
    {
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}

void main()
{
    createCLL();
    display();

    printf("\n");

    reverse();

    display();

    printf("\n");

    addAtBeg();

    display();
}
