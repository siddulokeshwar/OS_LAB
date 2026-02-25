#include<stdio.h>

int main(){
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    int array[size];
    printf("\nEnter array elemnts:");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("\nArray before deletion is:");
    for(int i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
    int pos;
    printf("\nEnter position to delete:");
    scanf("%d",&pos);
    for(int i=pos-1;i<size;i++){
        array[i] = array[i+1];
    }
    printf("\nArray after deletion is:");
    for(int i=0;i<size-1;i++){
        printf("%d\t",array[i]);
    }
    return 0;
}