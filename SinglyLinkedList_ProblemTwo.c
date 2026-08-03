#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = NULL;

    return newNode;
}

void display(struct Node *head) {
    struct Node *temp;

    if(head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    temp = head;

    printf("Current Queue: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(value);

    if(*head == NULL) {
        *head = newNode;
        return;
    }
    temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteByValue(struct Node **head, int value) {
    struct Node *temp;
    struct Node *prev;

    if(*head == NULL) {
        printf("Queue is empty. Deletion not possible.\n");
        return;
    }

    temp = *head;
    prev = NULL;

    if(temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Patient token deleted.\n");
        return;
    }

    while(temp == NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Patient token not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Patient token deletef\n");
}

void reversePrint(struct Node *head) {
    if(head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    reversePrint(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node *head = NULL;
    int choice, token;

    while(1)
    {
        printf("\n--- Hospital Patient Queue Operations ---\n");
        printf("1. Add Patient Token at End\n");
        printf("2. Delete Patient Token\n");
        printf("3. Display Queue Forward\n");
        printf("4. Display Queue Reverse\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter patient token: ");
                scanf("%d", &token);
                insertEnd(&head, token);
                display(head);
                break;

            case 2:
                printf("Enter token to delete: ");
                scanf("%d", &token);
                deleteByValue(&head, token);
                display(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                reversePrint(head);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
