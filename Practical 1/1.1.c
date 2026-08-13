#include<stdio.h>

void main(){
    int n;
    printf("Enter number of items in a row : ");
    scanf("%d",&n);
    char item[100][20];
    printf("Enter array %d elements : ",n);
    for(int i=0;i<n ;i++)
    {
        scanf("%s",&item[i]);
    }
    int h;
    printf("Enter number hours : ");
    scanf("%d",&h);
    int k;
    k=h%n;
    printf("\n");
    printf("-----Earlier order-----\n");
    for(int j=0; j<n ;j++){
        printf("%s  ",item[j]);
    }
    printf("\n");
    printf("-----New Order after %d hours-----\n",h);
    for(int j=k; j<n ;j++){
        printf("%s  ",item[j]);
    }
    for(int j=0; j<k ;j++){
        printf("%s  ",item[j]);
    }
    printf("\n");
}
