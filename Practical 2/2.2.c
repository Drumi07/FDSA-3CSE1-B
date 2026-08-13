#include<stdio.h>

//Iterative Search
void binarySearch(int arr[], int size, int plate)
{
    int low = 0;
    int high = size - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(plate == arr[mid])
        {
            printf("Book found at place %d\n", mid + 1);
            return;
        }
        else if(plate < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Book not found\n");
}

//Recursive Search
int binarySearchR(int arr[], int low, int high, int target)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target)
        return mid;
    if(target < arr[mid])
        return binarySearchR(arr, low, mid - 1, target);

    return binarySearchR(arr, mid + 1, high, target);
}

void main()
{
    int n;
    printf("Enter number of books in catalog : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d sorted book codes : ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int number;
    printf("Using Recursive Search :\n");
    printf("Enter book code you want to find: ");
    scanf("%d",&number);

    int result = binarySearchR(arr, 0, n - 1, number);

    if(result != -1)
        printf("Book found at position %d\n", result + 1);
    else
        printf("Book not found\n");

    printf("Using Iterative Search :\n");
    printf("Enter book code you want to find: ");
    scanf("%d",&number);

    binarySearch(arr, n, number);
}