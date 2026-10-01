#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node *n;
};

void insert_end(struct node **h, int d)
{
    struct node *temp, *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->d = d;

    if (*h == NULL){
        nn->n = nn;
        *h = nn;
        return;
    }

    temp = *h;

    while (temp->n != *h){
        temp = temp->n;
    }

    nn->n = *h;
    temp->n = nn;
}

void insert_front(struct node **h, int d)
{
    struct node *temp, *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->d = d;

    if (*h == NULL){
        nn->n = nn;
        *h = nn;
        return;
    }

    temp = *h;

    while (temp->n != *h){
        temp = temp->n;
    }

    nn->n = *h;
    temp->n = nn;
    *h = nn;
}

void insert_mid(struct node **h, int d, int pos)
{
    struct node *temp, *nn;

    if (*h == NULL){
        printf("List is empty\n");
        return;
    }

    if (pos == 1){
        insert_front(h, d);
        return;
    }

    nn = (struct node *)malloc(sizeof(struct node));
    nn->d = d;

    temp = *h;

    for (int i = 1; i < pos - 1; i++){
        temp = temp->n;
        if (temp == *h)
        {
            printf("Position out of range\n");
            free(nn);
            return;
        }
    }

    nn->n = temp->n;
    temp->n = nn;
}

void delete_end(struct node **h)
{
    struct node *temp, *del;
    if (*h == NULL){
        printf("Underflow\n");
        return;
    }

    if ((*h)->n == *h){
        del = *h;
        *h = NULL;
        free(del);
        return;
    }

    temp = *h;

    while (temp->n->n != *h){
        temp = temp->n;
    }

    del = temp->n;
    temp->n = *h;

    free(del);
}

void delete_front(struct node **h)
{
    struct node *temp, *del;
    if (*h == NULL){
        printf("Underflow\n");
        return;
    }

    if ((*h)->n == *h){
        del = *h;
        *h = NULL;
        free(del);
        return;
    }

    temp = *h;

    while (temp->n != *h){
        temp = temp->n;
    }

    del = *h;
    *h = (*h)->n;
    temp->n = *h;

    free(del);
}

void delete_mid(struct node **h, int pos)
{
    struct node *temp, *del;

    if (*h == NULL){
        printf("Underflow\n");
        return;
    }

    if (pos == 1){
        delete_front(h);
        return;
    }

    temp = *h;

    for (int i = 1; i < pos - 1; i++){
        temp = temp->n;
        if (temp == *h)
        {
            printf("Position out of range\n");
            return;
        }
    }

    if (temp->n == *h){
        printf("Position out of range\n");
        return;
    }

    del = temp->n;
    temp->n = del->n;

    free(del);
}

void display(struct node **h)
{
    struct node *temp;

    if (*h == NULL){
        printf("List is empty\n");
        return;
    }

    temp = *h;

    do{
        printf("%d -> ", temp->d);
        temp = temp->n;
    } while (temp != *h);

    printf("(HEAD)\n");
}

int main()
{
    struct node *head = NULL;
    int choice;
    int d,pos;

    while (1) {
        printf("\n--- Circle arrangement ---\n");
        printf("1. Add Person at beginning\n");
        printf("2. Add Person at end\n");
        printf("3. Add Person at a specific Position\n");
        printf("4. Remove Person from beginning\n");
        printf("5. Remove Person from end\n");
        printf("6. Remove Person from a specific Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Value you want to add at Front : ");
                scanf("%d",&d);
                insert_front(&head, d);
                break;

            case 2:
                printf("Enter Value you want to add at End : ");
                scanf("%d",&d);
                insert_end(&head, d);
                break;

            case 3:
                printf("Enter position at which you want to add : ");
                scanf("%d",pos);
                printf("Enter Value you want to add at specific position : ");
                scanf("%d",&d);
                insert_mid(&head, d, pos);
                break;

            case 4:
                delete_front(&head);
                break;

            case 5:
                delete_end(&head);
                break;

            case 6:
                printf("Enter position at which you want to add : ");
                scanf("%d",pos);
                delete_mid(&head, pos);
                break;
            
            case 7:
                display(&head);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}