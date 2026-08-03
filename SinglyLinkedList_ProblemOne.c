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

void insertFront(struct Node **head, int value) {
    struct Node *newNode;

    newNode = createNode(value);

    newNode->next = *head;
    *head = newNode;
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

void insertAtPosition(struct Node **head, int value, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if(position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if(position == 1) {
        insertFront(head, value);
        return;
    }

    newNode = createNode(value);
    temp = *head;

    for(i = 1; i < position - 1; i++) {
        if(temp == NULL) {
            printf("Invalid position! Position is beyond queue length.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    } 

    if(temp == NULL) {
        printf("Invalid position! Position is beyond queue length.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    struct Node *head = NULL;
    int choice, token, position;

    while(1)
    {
        printf("\n--- Hospital Patient Queue ---\n");
        printf("1. Insert Critical Patient at Front\n");
        printf("2. Insert Routine Patient at End\n");
        printf("3. Insert Priority Patient at Position\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter patient token: ");
                scanf("%d", &token);
                insertFront(&head, token);
                display(head);
                break;

            case 2:
                printf("Enter patient token: ");
                scanf("%d", &token);
                insertEnd(&head, token);
                display(head);
                break;

            case 3:
                printf("Enter patient token: ");
                scanf("%d", &token);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, token, position);
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
