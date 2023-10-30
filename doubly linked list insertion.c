#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*prev;
    struct node*next;

};

struct node*head;
struct node*tail;

void createDLL()
{
    struct node*newNode;
    head=NULL;

    int choice=1;
    while(choice)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("eneter the data\n");
        scanf("%d",&newNode->data);
        newNode->prev=NULL,newNode->next=NULL;

        if(head==NULL)
        {
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
         printf("do you want to continue\n");
         scanf("%d",&choice);

    }
}

void printList()
{
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d--->",ptr->data);
        ptr=ptr->next;
    }
}

void addAtBeg()
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert\n");
    scanf("%d",&newNode->data);
    newNode->prev=NULL;
    newNode->next=NULL;
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

void addAtEnd()
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert\n");
    scanf("%d",&newNode->data);
    newNode->prev=NULL;
    newNode->next=NULL;
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}

void insertAfter()
{
    int pos,i;
    printf("enter the position after which you want to insert the data\n");
    scanf("%d",&pos);

    if(pos==1)
    {
        addAtBeg();
    }
    else
    {
        struct node*newNode;
        struct node*temp;
        temp=head;
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data you want to insert after\n");
        scanf("%d",&newNode->data);

        while( i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;

    }
}

void delAtBeg()
{
    struct node*temp;

    if(head==NULL)
    {
        printf("list is already empty");

    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void delAtEnd()
{
    struct node*temp;

    if(tail==NULL)
    {
        printf("list is already empty");

    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
}

void delFromPos()
{
    int pos,i=1;
    struct node*temp;
    temp=head;
    printf("enter the position from which you want to delete the node\n");
    scanf("%d",&pos);

    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void reverseDLL()
{
    struct node*current;
    struct node*nextnode;
    current=head;

    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}

void main()
{
    createDLL();

    printf("linked list is\n");

    printList();
    printf("\n");

    addAtBeg();

    printf("linked list after addition at begining is\n");

    printList();
    printf("\n");



    addAtEnd();

    printf("linked list after addition at end is\n");

    printList();
    printf("\n");


   // printf("linked list after insertion at middle\n");

    insertAfter();

    printf("linked list after insertion at middle\n");

    printList();

    printf("\n");


    delAtBeg();

    printf("linked list after deletion at beginning \n");

    printList();

    printf("\n");

    delAtEnd();

    printf("linked list after deletion at the end\n");

    printList();

    printf("\n");

   // printf("linked list after deletion at middle\n");

    delFromPos();

    printf("linked list after deletion at middle\n");

    printList();

    printf("\n");

    reverseDLL();

    printf("linked list after reversing\n");

    printList();







}
