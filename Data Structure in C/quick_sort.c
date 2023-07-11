#include <stdio.h>

void swap(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int a[], int low, int high)
{
  int pivot = a[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (a[j] <= pivot)
    {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

void quickSort(int a[], int low, int high) 
{
  if (low < high)
  {
    int pi = partition(a, low, high);
    printf("Pivot: %d\n", a[pi]);
    printf("Array after partitioning: ");
    display(a, high + 1);
    printf("\n");
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

void display(int a[], int n) 
{ 
  for (int i = 0; i < n; i++) 
  {
    printf("%d  ", a[i]);
  }
}

int main() 
{
  int a[20], i, n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  quickSort(a, 0, n - 1);
  printf("Sorted array: ");
  display(a, n);
  return 0;
}
