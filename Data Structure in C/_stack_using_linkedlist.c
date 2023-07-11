#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
void push(int value)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Not able to push in the stack. Stack is empty.");
    }
    else
    {
        ptr->data = value;

        if(head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
}
void pop()
{
    int x;
    struct node* ptr;

    if(head == NULL)
    {
        printf("Unable to pop. Stack underflow.");
    }
    else
    {
        x = head->data;
        ptr = head;
        head = head->next;
        printf("%d ",ptr->data);
        free(ptr);

    }
}
void display()
{
    struct node* ptr=head;;
    if(ptr == NULL)
    {
        printf("underflow ");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
void peek()
{
    if(head == NULL)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("%d", head->data);
    }
}

int main()
{
    int choice;

    while(1)
    {
        //printf("Enter 1 for push operation\n");
       // printf("Enter 2 for display operation\n");
        //printf("Enter 3 for peek operation\n");
       // printf("Enter 4 for pop operation\n");
        //printf("Enter 5 for exiting the code\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                push(20);
                push(25);
                break;
            
            case 2:
                display();
                break;
                
            case 3:
                peek();
                break;
            
            case 4:
                pop();
                break;
                
            case 5:
                exit(0);
                break;

            default:
              //  printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}