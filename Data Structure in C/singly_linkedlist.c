#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void insertatstart()
{
    struct node *ptr;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Insert not allowed");
    }
    else
    {
        scanf("%d", &val);
        ptr->data = val;
        ptr->next = head;
        head = ptr;
    }
}

void insertatlast()
{
    struct node *ptr, *temp;
    int val;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("Insert not allowed");
    else
    {
        scanf("%d", &val);
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}

void insertatsp()
{
    int i, loc, val;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("Insert not allowed");
    else
    {
        scanf("%d", &val);
        ptr->data = val;
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void deletefirst()
{
    struct node *ptr;
    if (head == NULL)
        printf("List empty");
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
}

void deletelast()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
        printf("List empty");
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
}

void deletesp()
{
    struct node *ptr, *ptr1;
    int loc, i;
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
            return;
    }
    ptr1->next = ptr->next;
    free(ptr);
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("No elements");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void search()
{
    struct node *ptr;
    int item, flag;
    ptr = head;
    if (ptr == NULL)
        printf("Empty list");
    else
    {
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("Item found!!");
                return;
            }
            else
                flag = 1;
            ptr = ptr->next;
        }
        if (flag == 1)
            printf("Item not found!!");
    }
}

int main()
{
    char ch;
    printf("Singly Linked List Operations:\n");
    printf("a) Insert at beginning\n");
    printf("b) Insert at end\n");
    printf("c) Insert after specified node\n");
    printf("d) Delete at beginning\n");
    printf("e) Delete at end\n");
    printf("f) Delete after specified node\n");
    printf("g) Display\n");
    printf("h) Search an element\n");
    printf("i) Exit\n");

    while (ch != 'i')
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'a':
        {
            insertatstart();
            break;
        }
        case 'b':
        {
            insertatlast();
            break;
        }
        case 'c':
        {
            insertatsp();
            break;
        }
        case 'd':
        {
            deletefirst();
            break;
        }
        case 'e':
        {
            deletelast();
            break;
        }
        case 'f':
        {
            deletesp();
            break;
        }
        case 'g':
        {
            display();
            break;
        }
        case 'h':
        {
            search();
            break;
        }
        case 'i':
        {
            exit(0);
        }
        }
    }
    return 0;
}
