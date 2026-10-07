#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void join(int token)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Error: Queue is Full\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = token;

    printf("Front token: %d\n", queue[front]);
}

void serve()
{
    if (front == -1)
    {
        printf("Error: Queue is Empty\n");
        return;
    }

    printf("Served token: %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    if (front == -1)
        printf("Front token: Empty\n");
    else
        printf("Front token: %d\n", queue[front]);
}

int main()
{
    int choice, token;

    while (1)
    {
        printf("\n1. Join\n");
        printf("2. Serve\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter token number: ");
            scanf("%d", &token);
            join(token);
        }
        else if (choice == 2)
        {
            serve();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}