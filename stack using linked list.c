#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node*top=0;

void push(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display()
{
    struct node*temp;
    temp=top;
    while(temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }

}

void pop()
{
    struct node*temp;
    temp=top;

    if(top==0)
    {
        printf("stack is empty");

    }
    else
    {
        printf("%d",top->data);
        top=top->next;
        free(temp);
    }
}

void peek()
{
    if(top==0)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d",top->data);
    }
}


void main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    printf("\n");

    pop();

    printf("\n");

    display();

    printf("\n");

    peek();

    printf("\n");

    display();


}
