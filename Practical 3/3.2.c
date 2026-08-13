#include<stdio.h>

void bubbleSort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    }
    printf("\nSorted Array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter Total number of elements : ");
    scanf("%d",&n);
    int elements[n];
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&elements[i]);
    }
    printf("\nSorting Marks using Bubble Sort");
    bubbleSort(elements,n);
}