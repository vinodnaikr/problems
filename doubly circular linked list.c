#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};

struct node*head,*tail;

void createDCLL()
{
    struct node*newnode;
    int choice=1;
    head=NULL;

    while(choice)
    {


    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL)
    {
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
    printf("do you want to continue\n");
    scanf("%d",&choice);



    }
}

void display()
{
    struct node*ptr;
    ptr=head;
    while(ptr!=tail)
    {
      printf("%d-->",ptr->data);
      ptr=ptr->next;

    }
    printf("%d-->",ptr->data);
}

void addAtBeg()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert at beginning\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
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
        tail->next=head;
        head=newnode;
    }
}

void addAtEnd()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data to be inserted\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->next=tail->next;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

}

void addAtPos()
{
    struct node*newnode,*temp;
    int pos,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert\n");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    printf("enter the position where you want to insert data\n");
    scanf("%d",&pos);
    temp=head;

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=newnode;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;

}

void delAtBeg()
{
    struct node*temp;
    temp=head;
    head=head->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
}

void delAtEnd()
{
    struct node*temp;
    temp=tail;
    tail->prev->next=tail->next;
    tail=tail->prev;
    free(temp);
}

void delAtPos()
{
    struct node*ptr;
    int pos,i=1;
    printf("enter the position from where you want to delete the data\n");
    scanf("%d",&pos);
    ptr=head;

    while(i<pos)
    {
        ptr=ptr->next;
        i++;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    free(ptr);
}

void main()
{
    createDCLL();
    display();

    printf("\n");

    addAtBeg();

    display();

    printf("\n");

    addAtEnd();

    display();

    printf("\n");

    addAtPos();

    display();

    printf("\n");

    delAtBeg();

    display();

    printf("\n");

    delAtEnd();

    display();

    printf("\n");

    delAtPos();

    display();
}

