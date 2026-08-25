#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *n;
};

void insert_end(struct node **h,int d){
    struct node *temp, *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->d=d;
    nn->n=NULL;
    temp = *h;
    if(*h==NULL){
        *h=nn;
        return;
    }
    while (temp -> n != NULL) {
        temp = temp->n;
    }
    temp->n=nn;
}

void insert_front(struct node **h,int d){
    struct node  *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->d=d;
    nn->n=*h;
    *h = nn;
}

void insert_mid(struct node **h,int d,int pos){
    struct node *temp, *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->d=d;
    for(int i=0;i<pos-1;i++){
        temp = temp->n;
    }
    nn->n = temp->n;
    temp->n=nn;
}

void main() {
    struct node *head = NULL, *temp, *newnode;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->d);

        newnode->n = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->n != NULL) {
                temp = temp->n;
            }

            temp->n = newnode;
        }

        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    }

    insert_end(&head,15);
    insert_front(&head,20);
    insert_front(&head,30);
    insert_mid(&head,29,3);
    insert_mid(&head,25,5);
    insert_end(&head,18);

    temp = head;
    printf("\nQueue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->d);
        temp = temp->n;
    }
    printf("NULL\n");
}