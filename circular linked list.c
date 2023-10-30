#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node*head;

void createCLL()
{
    int choice=1;
    struct node*newNode;
    struct node*temp;
    head=NULL;

        while(choice)
        {
            newNode=(struct node*)malloc(sizeof(struct node));
            printf("enter the data \n");
            scanf("%d",&newNode->data);
            newNode->next=NULL;

                if(head==NULL)
                {
                    head=temp=newNode;
                }
                else
                {
                    temp->next=newNode;
                    temp=newNode;
                }
                temp->next=head;
                printf("do you want to continue\n");
                scanf("%d",&choice);
        }
}

void display()
{
    struct node*temp;
    temp=head;
    while(temp->next!=head)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("%d--->",temp->data);
}

void addAtBeg()
{
    struct node*newnode;
    struct node*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("enter the data to be inserted\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }


    while(ptr->next!=head->next)
    {
        ptr=ptr->next;
    }

    ptr->next=head;
}

void addAtEnd()
{
    struct node*newnode;
    struct node*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data to be inserted\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=head;
    }

}

void addAtPos()
{
    struct node*newnode;
    struct node*ptr;
    int pos,i=1;

    printf("enter the position at which you want to insert data\n");
    scanf("%d",&pos);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(pos==1)
    {
        addAtBeg();
    }
    else
    {


    ptr=head;

    while(i<pos-1)
    {
        ptr=ptr->next;
        i=i++;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;


    }
}

void deleteAtBeg()
{
   struct node*temp;
   struct node*temp1;
   temp1=head;
   temp=head;
   while(temp->next!=head)
   {
       temp=temp->next;
   }
   temp->next=head->next;
   head=head->next;
   free(temp1);
}

void deleteAtEnd()
{
    struct node*ptr;
    ptr=head;
    while(ptr->next->next!=head)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=head;



}

void deleteAtPos()
{
    struct node*temp;
    struct node*temp1;
    int pos,i=1;
    temp=head;
    printf("enter the position from which you want to delete the data\n");
    scanf("%d",&pos);

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);




}


void main()
{
    createCLL();
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

    deleteAtBeg();

    display();

    printf("\n");

    deleteAtEnd();


    display();

    printf("\n");


    deleteAtPos();


    display();



}

