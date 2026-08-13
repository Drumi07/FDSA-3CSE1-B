#include<stdio.h>
//Iterative Search
void linearSearch(int arr[],int size,int plate){
    int index=0;
    while(index<size){
        if(plate == arr[index]){
            printf("Vehicle found at place %d",index+1);
            break;
        }
        index++;
    }
}
//Recursive Search
int linearSearchR(int arr[], int n, int target, int index)
{
    if (index >= n)
        return -1;

    if (arr[index] == target)
        return index;

    return linearSearchR(arr, n, target, index + 1);
}

void main(){
    int n;
    printf("Enter number of cars in parking : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d car plate numbers : ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int number;
    printf("Using Recursive Search :\n");
    printf("Enter number of car in parking you want to find: ");
    scanf("%d",&number);

    int result = linearSearchR(arr, n, number, 0);

    if (result != -1)
        printf("Target plate found at position %d\n", result + 1);
    else
        printf("Target plate not found\n");

    printf("Using Iterative Search :\n");
    printf("Enter number of car in parking you want to find: ");
    scanf("%d",&number);

    linearSearch(arr, n, number);
}