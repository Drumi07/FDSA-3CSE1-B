#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("Top tray: %d\n", stack[top]);
}

void pop()
{
    if (top == -1)
    {
        printf("Error: Stack Underflow\n");
        return;
    }
    printf("Taken tray: %d\n", stack[top]);
    top--;
    if (top == -1)
        printf("Top tray: Empty\n");
    else
        printf("Top tray: %d\n", stack[top]);
}

int main()
{
    int n, choice, value;
    printf("Enter capacity of stack: ");
    scanf("%d", &n);

    int stack[n];
    top = -1;

    while (1)
    {
        printf("\n1. Place tray (Push)\n");
        printf("2. Take tray (Pop)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (top == n - 1)
            {
                printf("Error: Stack is Full\n");
            }
            else
            {
                printf("Enter tray number: ");
                scanf("%d", &value);

                top++;
                stack[top] = value;

                printf("Top tray: %d\n", stack[top]);
            }
        }
        else if (choice == 2)
        {
            if (top == -1)
            {
                printf("Error: Stack is Empty\n");
            }
            else
            {
                printf("Taken tray: %d\n", stack[top]);
                top--;

                if (top == -1)
                    printf("Top tray: Empty\n");
                else
                    printf("Top tray: %d\n", stack[top]);
            }
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