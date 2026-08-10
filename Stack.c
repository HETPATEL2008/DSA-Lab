#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow!", value);
        return;
    }

    top++;
    stack[top] = value;
    printf("%d pushed into the stack.\n", value);
}

void pop() {

    int deleteValue;

    if(top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    deleteValue = stack[top];
    top--;
    printf("%d popped from the stack.\n", deleteValue);
}

void peak() {
    if(top == -1) {
        printf("Stack is empty. No top element!\n");
        return;
    }

    printf("The top element is %d.", stack[top]);
}

void display() {

    if(top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements are: \n");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();   
                break;

            case 3:
                peak();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}
