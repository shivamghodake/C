#include <stdio.h>
int binarysearch(int arr[], int beg, int end, int skey)
{
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == skey) 
        {
            return 1;
        }
        if (arr[mid] < skey) 
        {
            beg = mid + 1;
        }
        else 
        {
            end = mid - 1;
        }
    }
    return 0; 
}
int main() 
{
    int n, skey;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the search key: ");
    scanf("%d", &skey);

    if (binarysearch(arr, 0, n - 1, skey)) 
    {
        printf("Number present\n");
    } 
    else 
    {
        printf("Number absent\n");
    }
    return 0;
}
