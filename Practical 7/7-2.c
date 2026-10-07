#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char patient[50];
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void arrive(char name[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->patient, name);
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Current front patient: %s\n", front->patient);
}

void attend()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Error: Ward is Empty\n");
        return;
    }

    printf("Attended patient: %s\n", front->patient);

    temp = front;
    front = front->next;

    free(temp);

    if (front == NULL)
        rear = NULL;

    if (front == NULL)
        printf("Current front patient: Empty\n");
    else
        printf("Current front patient: %s\n", front->patient);
}

int main()
{
    int choice;
    char name[50];

    while (1)
    {
        printf("\n1. Arrive\n");
        printf("2. Attend\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter patient name: ");
            scanf("%s", name);
            arrive(name);
        }
        else if (choice == 2)
        {
            attend();
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