#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insertion_beginning();
void insertion_last();
void insertion_after();
void deletion_beginning();
void deletion_last();
void deletion_after();
void display();
void search();

int main() {
    char choice = ' ';
    do {
        printf("\nSelect an operation:\n");
        printf("a) Insert at beginning\n");
        printf("b) Insert at end\n");
        printf("c) Insert after specified node\n");
        printf("d) Delete at beginning\n");
        printf("e) Delete at end\n");
        printf("f) Delete after specified node\n");
        printf("g) Display\n");
        printf("h) Search an element\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                insertion_beginning();
                break;
            case 'b':
                insertion_last();
                break;
            case 'c':
                insertion_after();
                break;
            case 'd':
                deletion_beginning();
                break;
            case 'e':
                deletion_last();
                break;
            case 'f':
                deletion_after();
                break;
            case 'g':
                display();
                break;
            case 'h':
                search();
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 'h');

    return 0;
}

void insertion_beginning() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
    } else {
        printf("Enter the value to be inserted: ");
        scanf("%d", &item);
        ptr->data = item;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("Element inserted at the beginning\n");
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
    } else {
        printf("Enter the value to be inserted: ");
        scanf("%d", &item);
        ptr->data = item;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("Element inserted at the end\n");
    }
}

void insertion_after() {
    struct node *ptr, *temp;
    int item, value;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Overflow\n");
    } else {
        printf("Enter the value to be inserted: ");
        scanf("%d", &item);
        ptr->data = item;

        printf("Enter the value after which node to be inserted: ");
        scanf("%d", &value);

        if (head == NULL) {
            printf("List is empty, cannot insert after\n");
        } else {
            temp = head;
            do {
                if (temp->data == value) {
                    ptr->prev = temp;
                    ptr->next = temp->next;
                    temp->next->prev = ptr;
                    temp->next = ptr;
                    printf("Element inserted after specified node\n");
                    return;
                }
                temp = temp->next;
            } while (temp != head);
            printf("Specified node not found\n");
        }
    }
}

void deletion_beginning() {
    struct node *temp;
    if (head == NULL) {
        printf("Underflow\n");
    } else if (head->next == head) {
        head = NULL;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        head = temp->next;
    }
    printf("Element deleted from the beginning\n");
}

void deletion_last() {
    struct node *ptr;
    if (head == NULL) {
        printf("Underflow\n");
    } else if (head->next == head) {
        head = NULL;
    } else {
        ptr = head;
        if (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
    }
    printf("Element deleted from the end\n");
}

void deletion_after() {
    struct node *ptr, *temp;
    int value;
    if (head == NULL) {
        printf("Underflow\n");
    } else {
        printf("Enter the value after which node to be deleted: ");
        scanf("%d", &value);

        ptr = head;
        while (ptr->next != head) {
            if (ptr->data == value) {
                temp = ptr->next;
                ptr->next = temp->next;
                temp->next->prev = ptr;
                free(temp);
                printf("Element deleted after specified node\n");
                return;
            }
            ptr = ptr->next;
        }
        printf("Specified node not found\n");
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("Elements in the list: ");
        while (ptr->next != head) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;

    if (ptr == NULL) {
        printf("Empty List\n");
    } else {
        printf("Enter the element to search: ");
        scanf("%d", &item);

        if (head->data == item) {
            printf("Item found at position %d\n", i + 1);
            flag = 0;
        } else {
            while (ptr->next != head) {
                if (ptr->data == item) {
                    printf("Item found at position %d\n", i + 1);
                    flag = 0;
                    break;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0) {
            printf("Item not found\n");
        }
    }
}
