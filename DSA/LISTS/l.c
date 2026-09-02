#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;


// DISPLAY
void display() {
    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}


// INSERT AT BEGINNING
void insert_beg() {

    struct node *ins = malloc(sizeof(struct node));

    printf("Enter extra term: ");
    scanf("%d", &ins->data);

    ins->next = head;
    head = ins;
}


// INSERT AT END
void insert_end() {

    struct node *ins = malloc(sizeof(struct node));

    printf("Enter extra term: ");
    scanf("%d", &ins->data);

    ins->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = ins;
        return;
    }

    struct node *ptr = head;

    // Go to last node
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Connect last node to new node
    ptr->next = ins;
}


// DELETE AT BEGINNING
void delete_beg() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *del = head;

    head = head->next;

    free(del);
}


// DELETE AT END
void delete_end() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *ptr = head;

    // Go to second-last node
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    // ptr = second-last node
    free(ptr->next);

    // Make second-last node the last node
    ptr->next = NULL;
}


int main() {

    int n;

    printf("Enter no of lists: ");
    scanf("%d", &n);


    // CREATE INITIAL LIST
    for (int i = 0; i < n; i++) {

        struct node *new = malloc(sizeof(struct node));

        printf("Enter term: ");
        scanf("%d", &new->data);

        new->next = NULL;

        if (head == NULL) {
            head = new;
            temp = new;
        }
        else {
            temp->next = new;
            temp = new;
        }
    }


    printf("\nOriginal list: ");
    display();


    int choice;

    printf("\n1. Insert beginning");
    printf("\n2. Insert end");
    printf("\n3. Delete beginning");
    printf("\n4. Delete end");
    printf("\nEnter choice: ");
    scanf("%d", &choice);


    if (choice == 1) {
        insert_beg();
    }
    else if (choice == 2) {
        insert_end();
    }
    else if (choice == 3) {
        delete_beg();
    }
    else if (choice == 4) {
        delete_end();
    }
    else {
        printf("Invalid choice\n");
    }


    printf("Final list: ");
    display();

    return 0;
}