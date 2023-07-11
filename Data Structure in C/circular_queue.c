#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return 1;
    else
        return 0;
}
int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void insert(int item) {
    if (isFull()) {
        printf("Queue is full. Insertion not possible.\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Element %d inserted successfully.\n", item);
    }
}

void displayRear() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}

void displayFront() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n")
        printf("2. Display Rear\n");
        printf("3. Display Front\n");
 

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                displayRear();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                if (isFull())
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 5:
                if (isEmpty())
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
