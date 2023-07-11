#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int value)
{
  struct node*ptr;
  ptr=(struct node*)malloc(sizeof(struct node));
  ptr->data=value;
  ptr->next=NULL;
  if(front==NULL && rear==NULL)
  {
    front=rear=ptr;
  }
  else
  {
    rear->next=ptr;
    rear=ptr;
  }
}

void dequeue()
{ int x;
  if(front==NULL)
  {
    printf("\n queue empty \n");
  }
  else
 {
  struct node * temp=front;
  int temp_data= front->data;
   front=front->next;
   free(temp);
  if(front==NULL)
  {
    rear=NULL;
  }
 }         
}
           
void display()
 {
   struct node*temp=front;
  if(front==NULL && rear==NULL)
  {
    printf("queue empty");
  }
  else
  { 
    temp=front;
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
  }
 }
           
 void display_front()
  {
  printf("%d",front->data);
  }
 void display_rear()
   {
  printf("%d",rear->data);     
   }
 int main()
  {  while(1)
  {
     int choice;
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        enqueue(20);
        enqueue(25);
        break;
        
      case 2:
        display();
        break;
        
      case 3:
        display_front();
        break;
        
      case 4:
       display_rear();
        break;
        
      case 5:
        if(front==NULL && rear==NULL)
        {
          printf("Queue empty");
        }
        else{
          dequeue();
        }
        break;
        
      case 6:
        exit(0);
        break;
    }
    }
  
   return 0;
  }