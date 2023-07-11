#include<stdio.h>
#define MAX 10

int dequeue[MAX];
int front = -1, rear = -1;

int is_empty() {
  if (front == -1 && rear == -1)
    return 1;
  else
    return 0;
}

int is_full() {
  if (rear == MAX - 1)
    return 1;
  else
    return 0;
}

void insert_rear(int element) {
  if (is_full()) {
    printf("Overflow: Queue is full.\n");
  }
  else {
    if (is_empty()) {
      front = rear = 0;
    }
    else {
      rear++;
    }
    dequeue[rear] = element;
    printf("Element %d inserted at the rear.\n", element);
  }
}

void delete_rear() {
  if (is_empty()) {
    printf("Underflow: Queue is empty.\n");
  }
  else {
    printf("Element %d deleted from the rear.\n", dequeue[rear]);
    rear--;
    if (rear == -1)
      front = -1;
  }
}

void insert_front(int element) {
  if (is_full()) {
    printf("Overflow: Queue is full.\n");
  }
  else {
    if (is_empty()) {
      front = rear = 0;
    }
    else {
      front--;
    }
    dequeue[front] = element;
    printf("Element %d inserted at the front.\n", element);
  }
}

void delete_front() {
  if (is_empty()) {
    printf("Underflow: Queue is empty.\n");
  }
  else {
    printf("Element %d deleted from the front.\n", dequeue[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display() {
  if (is_empty()) {
    printf("Queue is empty.\n");
  }
  else {
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
      printf("%d\n", dequeue[i]);
    }
  }
}

int main() {
  char choice;
  int element;

  while (1) {
    printf("Enter your choice:\n");
    printf("a) Insert front\n");
    printf("b) Insert rear\n");
    printf("c) Delete rear\n");
    printf("d) Delete front\n");
    printf("e) Exit\n");
    printf("f) Display\n");

    scanf(" %c", &choice);
    switch (choice) {
      case 'a':
        printf("Enter element to insert at the front: ");
        scanf("%d", &element);
        insert_front(element);
        break;
      case 'b':
        printf("Enter element to insert at the rear: ");
        scanf("%d", &element);
        insert_rear(element);
        break;
      case 'c':
        delete_rear();
        break;
      case 'd':
        delete_front();
        break;
      case 'e':
        return 0;
      case 'f':
        display();
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}
