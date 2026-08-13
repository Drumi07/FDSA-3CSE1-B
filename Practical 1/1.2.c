#include<stdio.h>

int main()
{
    int n;
    printf("Enter number of books : ");
    scanf("%d",&n);
    int arr[n];
    int count[n];
    printf("Enter book ID of %d books : ",n);
    for(int i=0;i<n ;i++)
    {
        scanf("%d",&arr[i]);
        count[i]=0;
    }
    
    printf("Books borrowed more than once : ");
    for(int i=0;i<n ;i++)
    {
        int freq=0;
        for(int j=0; j<n ; j++){
            if(arr[i]==arr[j]){
                freq++;
            }
        }
        if(freq>1 && count[i]==0){
            printf("%d\n",arr[i]);
            count[i]=1;
            for(int k=i+1;k<n;k++){
                if(arr[i]==arr[k]){
                    count[k]=1;
                }
            }
        }
    }
    return 0;
}