#include<stdio.h>

int main(){
    int len;
    printf("\nEnter size of square matrix:");
    scanf("%d",&len);
    int mat[len][len];
    printf("\nEnter Multidimensional array:\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(i>j){
                sum += mat[i][j];
            }
        }
    }
    printf("\nSum of Left diagonal matrix is:%d",sum);
    return 0;
}