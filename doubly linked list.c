#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head,*new_node;

void  create()
{
    head=NULL;
    struct node*temp;
    temp=head;
    int choice=0;
    int k;
    printf("enter no of node\n");
    scanf("%d",&k);
    int data;
    while(choice<k)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;
        new_node->prev=NULL;
        if(head==NULL)
        {
            head=temp=new_node;
        }
        else
        {
            temp->next=new_node;
            new_node->prev=temp;
            temp=new_node;
        }
        choice=choice+1;


  }
}
void print_list()
{
    struct node*temp;
    temp=head;

    while(temp!=NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
}
void main()
{
    create();

    printf("the linked list is\n");

    print_list();
}

