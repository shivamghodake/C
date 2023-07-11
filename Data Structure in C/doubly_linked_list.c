#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertAtBeginning(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head == NULL) {
        tail = newNode;
    } else {
        head->prev = newNode;
    }
    
    head = newNode;
    printf("%d inserted at the beginning\n", data);
}

void insertAtEnd(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    
    if (tail == NULL) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    
    tail = newNode;
    printf("%d inserted at the end\n", data);
}

void insertAfter(int data, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = current;
    newNode->next = current->next;
    
    if (current == tail) {
        tail = newNode;
    } else {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    printf("%d inserted after %d\n", data, key);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head;
    head = head->next;
    
    if (head == NULL) {
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    
    printf("%d deleted from the beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = tail;
    tail = tail->prev;
    
    if (tail == NULL) {
        head = NULL;
    } else {
        tail->next = NULL;
    }
    
    printf("%d deleted from the end\n", temp->data);
    free(temp);
}

void deleteAfter(struct node *prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Error: Node to be deleted cannot be NULL\n");
        return;
    }
    
    struct node *nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = prevNode;
    }
    
    printf("Node with data %d deleted\n", nodeToDelete->data);
    free(nodeToDelete);
}

void search(int key) {
    struct node *current = head;
    int position = 0;
    
    while (current != NULL) {
        position++;
        if (current->data == key) {
            printf("Element found at position %d\n", position);
            return;
        }
        current = current->next;
    }
    
    printf("Element not found\n");
}

void display() {
    struct node *current = head;
    
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char choice;
    int data, key;
    
    do {
        printf("Menu:\n");
        printf("a) Insert at beginning\n");
        printf("b) Insert at end\n");
        printf("c) Insert after specified node\n");
        printf("d) Delete at beginning\n");
        printf("e) Delete at end\n");
        printf("f) Delete after specified node\n");
        printf("g) Display\n");
        printf("h) Search an element\n");
        printf("i) Quit\n");
        
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 'b':
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 'c':
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the key after which data needs to be inserted: ");
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
                printf("Enter the key after which node needs to be deleted: ");
                scanf("%d", &key);
                struct node *current = head;
                while (current != NULL && current->data != key) {
                    current = current->next;
                }
                deleteAfter(current);
                break;
            case 'h':
                printf("Enter the element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 'g':
                display();
                break;
            case 'i':
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 'i');
    
    return 0;
}
