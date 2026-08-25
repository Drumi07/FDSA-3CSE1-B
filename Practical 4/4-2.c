#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *n;
};

void insert_end(struct node **h, int d) {
    struct node *temp, *nn;

    nn = (struct node *)malloc(sizeof(struct node));
    nn->d = d;
    nn->n = NULL;

    temp = *h;

    if (*h == NULL) {
        *h = nn;
        return;
    }

    while (temp->n != NULL) {
        temp = temp->n;
    }

    temp->n = nn;
}

void insert_front(struct node **h, int d) {
    struct node *nn;

    nn = (struct node *)malloc(sizeof(struct node));

    nn->d = d;
    nn->n = *h;

    *h = nn;
}

void insert_mid(struct node **h, int d, int pos) {
    struct node *temp, *nn;

    if (pos == 1) {
        insert_front(h, d);
        return;
    }

    temp = *h;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->n;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    nn = (struct node *)malloc(sizeof(struct node));
    nn->d = d;

    nn->n = temp->n;
    temp->n = nn;
}

void delete_value(struct node **h, int d) {
    struct node *temp, *del;

    if (*h == NULL) {
        printf("Queue is empty\n");
        return;
    }

    if ((*h)->d == d) {
        del = *h;
        *h = (*h)->n;
        free(del);

        printf("Patient %d deleted\n", d);
        return;
    }

    temp = *h;

    while (temp->n != NULL && temp->n->d != d) {
        temp = temp->n;
    }

    if (temp->n == NULL) {
        printf("Patient %d not found\n", d);
        return;
    }

    del = temp->n;
    temp->n = del->n;

    free(del);

    printf("Patient %d deleted\n", d);
}

void display_forward(struct node *h) {
    struct node *temp = h;

    printf("Queue from front to back: ");

    while (temp != NULL) {
        printf("%d -> ", temp->d);
        temp = temp->n;
    }

    printf("NULL\n");
}

void reverse_print(struct node *h) {
    if (h == NULL) {
        return;
    }

    reverse_print(h->n);

    printf("%d -> ", h->d);
}

int main() {
    struct node *head = NULL, *temp, *newnode;
    int choice = 1;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->d);

        newnode->n = NULL;

        if (head == NULL) {
            head = newnode;
        }
        else {
            temp = head;
            while (temp->n != NULL) {
                temp = temp->n;
            }
            temp->n = newnode;
        }
        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    }

    insert_end(&head, 15);
    insert_front(&head, 20);
    insert_front(&head, 30);
    insert_mid(&head, 29, 3);
    insert_mid(&head, 25, 5);
    insert_end(&head, 18);

    printf("\nQueue after insertion:\n");
    display_forward(head);

    int value;
    printf("\nEnter patient token to delete: ");
    scanf("%d", &value);

    delete_value(&head, value);

    printf("\nRemaining Queue:\n");
    display_forward(head);

    printf("\nQueue from back to front: ");

    reverse_print(head);
    printf("NULL\n");

    return 0;
}