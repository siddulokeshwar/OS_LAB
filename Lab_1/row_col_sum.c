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
    int rsum[len],csum[len];
    for(int i=0;i<len;i++){
        int sum=0;
        for(int j=0;j<len;j++){
            sum += mat[i][j];
        }
        rsum[i] =sum;
    }
    printf("\nRow elemnts sum is:");
    for(int i=0;i<len;i++){
        printf("%d\t",rsum[i]);
    }
    for(int i=0;i<len;i++){
        int sum=0;
        for(int j=0;j<len;j++){
            sum += mat[j][i];
        }
        csum[i] = sum;
    }
    printf("\nColumn elemnts sum is:");
    for(int i=0;i<len;i++){
        printf("%d\t",csum[i]);
    }
}