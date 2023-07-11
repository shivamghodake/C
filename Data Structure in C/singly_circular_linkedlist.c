//C program to implement circular singly linked list and perform the following operations a) Insert
//at beginning b) Insert at end c) Insert after specified node d) delete at beginning e) delete at end
//f) delete after specified node g) display h) search an element
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct node *current = head;
        while(current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning\n", data);
}

void insertAtEnd(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct node *current = head;
        while(current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end\n", data);
}

void insertAfter(int data, int key) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct node *current = head;
        do {
            if(current->data == key) {
                newNode->next = current->next;
                current->next = newNode;
                printf("Inserted %d after %d\n", data, key);
                return;
            }
            current = current->next;
        } while(current != head);
        printf("%d not found in the list\n", key);
    }
}

void deleteAtBeginning() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    while(current->next != head) {
        current = current->next;
    }
    current->next = head->next;
    printf("Deleted %d from the beginning\n", head->data);
    free(head);
    head = current->next;
}

void deleteAtEnd() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    struct node *previous = NULL;
    while(current->next != head) {
        previous = current;
        current = current->next;
    }
    previous->next = head;
    printf("Deleted %d from the end\n", current->data);
    free(current);
}

void deleteAfter(int key) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    struct node *previous = NULL;
    do {
        if(current->data == key) {
            if(current->next == head) {
                printf("Cannot delete the next node as it is the first node\n");
                return;
            }
            previous = current;
            current = current->next;
            previous->next = current->next;
            printf("Deleted %d after %d\n", current->data, key);
            free(current);
            current = previous->next;
            return;
        }
        current = current->next;
    } while(current != head);
    printf("%d not found in the list\n", key);
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Singly Linked List: ");
    struct node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);
    printf("\n");
}

void search(int data) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;
    int position = 1;
    do {
        if(current->data == data) {
            printf("%d found at position %d\n", data, position);
            return;
        }
        current = current->next;
        position++;
    } while(current != head);
    printf("%d not found in the list\n", data);
}

int main() {
    char choice;
    int data, key;

    printf("Circular Singly Linked List Operations:\n");
    printf("a) Insert at beginning\n");
    printf("b) Insert at end\n");
    printf("c) Insert after specified node\n");
    printf("d) Delete at beginning\n");
    printf("e) Delete at end\n");
    printf("f) Delete after specified node\n");
    printf("g) Display\n");
    printf("h) Search an element\n");

    do {
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 'b':
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 'c':
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter key: ");
                scanf("%d", &key);
                insertAfter(data, key);
                break;
            case 'd':
                deleteAtBeginning();
                break;
            case 'e':
                deleteAtEnd();
                break;
            case 'f':
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 'g':
                display();
                break;
            case 'h':
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
        }
    } while(choice != 'i');

    return 0;
}
