#include <stdio.h>

int main() {
    int a[6], i, value, flag = 0;

    printf("Enter 6 integers for the array:\n");
    for (i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &value);

    printf("Array elements: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < 6; i++) {
        if (a[i] == value) {
            printf("%d found at index %d\n", value, i);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Element not found\n");
    }

    return 0;
}
