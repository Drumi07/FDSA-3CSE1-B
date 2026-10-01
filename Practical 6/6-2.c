#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[100];
    struct Node *next;
};

struct Node *top = NULL;

void visit(char page[])
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->page, page);
    newNode->next = top;
    top = newNode;
    printf("Current page: %s\n", top->page);
}

void back()
{
    struct Node *temp;
    if (top == NULL){
        printf("Error: No previous page\n");
        return;
    }

    temp = top;
    top = top->next;
    free(temp);
    printf("Current page: %s\n", top->page);
}

int main()
{
    int choice;
    char page[100];

    printf("Visit the first page:\n");
    scanf("%s", page);
    visit(page);

    while (1)
    {
        printf("\n1. Visit page\n");
        printf("2. Back\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter page: ");
                    scanf("%s", page);
                    visit(page);
                    break;

            case 2: back();
                    break;

            case 3: return 0;
                    
            default: printf("Invalid choice\n");
                     break;
        }
    }
    return 0;
}