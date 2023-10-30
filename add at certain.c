#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link
};

void create_list();
void random_insert();
void display_list();

int main()
{
 create_list();
 random_list();
 display_list();
 return 0;
}

void create_list()
{
    struct node*head=malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=2;
    current->link=NULL;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;

    head->link->link=current;


}

void random_insert()
{
    int i,position,value;
    struct node*ptr,*temp;

    ptr=(struct node*)malloc(sizeof(struct node));

    if(ptr==NULL)
    {
        printf("\nOVER FLOW\");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d",&value);
        ptr->data=value;

        printf("Enter location after which you want to insert\n");
        scanf("\n%d",&position);
        temp=head;

        for(i=0;i<position;i++)
        {
            temp=temp->link;

            if(temp==NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
            else
            {
                sjnxncd;
            }
        }
