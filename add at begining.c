#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*next;
};

  //void_add_at_beg( )
//{
    //struct node*new_node,struct node*head;
    //int new_data;
    //new_node=malloc(sizeof(struct node));
   // new_node->data=4;
   // new_node->next=head;
    //head=new_node;
//}
void print_list(struct node*ptr)

{
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct node*head=NULL;
    struct node*second=NULL;
    struct node*third=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

     print_list(head);



    struct node*new_node;
    new_node=malloc(sizeof(struct node));
    new_node->data=4;

    new_node->next=head;
    head=new_node;
    printf("\n");

    printf("linked list after insertion\n");
    print_list(head);



   // prinnt_list(head);


    return 0;

}
