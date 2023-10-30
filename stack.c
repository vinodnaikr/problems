#include<stdio.h>
#define MAX 4
int stack[MAX];
int top=-1;

void push()
{
    int x;
    printf("enter the data\n");
    scanf("%d",&x);

    if(top==MAX-1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("underflow");

    }
    else
    {
        item=stack[top];
        top--;
        printf("%d",item);
    }
}

void peek()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else
    {
        printf("%d",stack[top]);
    }
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}

void main()
{
    int choice;



    do
    {
        printf("enter choice : 1:push 2:pop 3:peek 4:display");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: peek();
            break;

            case 4: display();
            break;
        }
    }
        while(choice!=0);

}
