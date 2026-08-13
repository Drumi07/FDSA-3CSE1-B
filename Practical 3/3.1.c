#include<stdio.h>

void insertion(int arr[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("\nSorted Marks : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void selection(int arr[],int n){
    int min,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
        if(arr[min]>arr[j]){
            min=j;
        }
    }
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    }
    printf("\nSorted Marks : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

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
    printf("\nSorted Marks : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter Total number of students : ");
    scanf("%d",&n);
    int marks[n];
    printf("Enter marks of students : ");
    for(int i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }
    printf("\nSorting Marks using Insertion Sort\n");
    insertion(marks,n);
    printf("\nSorting Marks using Selection Sort");
    selection(marks,n);
    printf("\nSorting Marks using Bubble Sort");
    bubbleSort(marks,n);
}