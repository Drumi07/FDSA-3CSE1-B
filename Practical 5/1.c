#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char song[50];
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(char song[]) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));

    strcpy(nn->song, song);
    nn->prev = NULL;
    nn->next = head;

    if (head != NULL)
        head->prev = nn;

    head = nn;
}

void insert_end(char song[]) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    strcpy(nn->song, song);
    nn->next = NULL;

    if (head == NULL) {
        nn->prev = NULL;
        head = nn;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
    nn->prev = temp;
}

void insert_after(char given[], char song[]) {
    struct node *temp = head;
    struct node *nn;

    while (temp != NULL && strcmp(temp->song, given) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Song \"%s\" not found.\n", given);
        return;
    }

    nn = (struct node *)malloc(sizeof(struct node));
    strcpy(nn->song, song);

    nn->prev = temp;
    nn->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = nn;

    temp->next = nn;
}

void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

int count() {
    int c = 0;
    struct node *temp = head;

    while (temp != NULL) {
        c++;
        temp = temp->next;
    }

    return c;
}

void display() {
    struct node *temp = head;

    printf("Playlist: ");

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%s", temp->song);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;
    char song[50], given[50];

    while (1) {
        printf("\n--- Music Player ---\n");
        printf("1. Add song at beginning\n");
        printf("2. Add song at end\n");
        printf("3. Insert song after a specific song\n");
        printf("4. Remove first song\n");
        printf("5. Count songs\n");
        printf("6. Display playlist\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);

                insert_begin(song);
                display();
                break;

            case 2:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);

                insert_end(song);
                display();
                break;

            case 3:
                printf("Enter song after which to insert: ");
                scanf(" %[^\n]", given);

                printf("Enter new song name: ");
                scanf(" %[^\n]", song);

                insert_after(given, song);
                display();
                break;

            case 4:
                delete_begin();
                display();
                break;

            case 5:
                printf("Number of songs = %d\n", count());
                display();
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}