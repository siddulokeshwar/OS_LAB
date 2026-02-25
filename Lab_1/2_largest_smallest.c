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
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] =temp;
            }
        }
    }
    printf("\nArray is:");
    for(int i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
    printf("\nSecond Largest element is:%d",array[size-2]);
    printf("\nSecond smallest elemnt is:%d",array[1]);
    return 0;
} 