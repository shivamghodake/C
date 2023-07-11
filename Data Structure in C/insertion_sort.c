#include<stdio.h>

void insertion_sort(int a[], int n) {
  int i, j, skey;
  for (i = 1; i < n; i++) {
    skey = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > skey) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = skey;
  }
}

void display(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int a[20], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Array before sorting: ");
  display(a, n);
  insertion_sort(a, n);
  printf("Array after sorting: ");
  display(a, n);
  return 0;
}
