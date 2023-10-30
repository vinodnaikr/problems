#include<stdio.h>

#define N 5
queue[N];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(rear==N-1)
        printf("overflow");
    else if(rear==-1 && front==-1)
    {
      front=rear=0;
      queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("queue is empty");
    else if(front==rear)
        front=rear=-1;
    else
    {
        printf("the deleted element is: %d",queue[front]);
        front++;
    }
}

void display()
{
    int i ;
    if(rear==-1 && front==-1)
        printf("queue is empty");
    else
    {
        for(i=front; i<rear+1; i++)
            printf("%d",queue[i]);
    }
}

void peek()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty");
    else
        printf("%d",queue[front]);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("\n");

    display();

    printf("\n");

    dequeue();

    printf("\n");

    display();


    return 0;
}
