/*
 * Frequency Distribution of elements of array.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include<stdio.h>

int** findFreqDis(int* inputArray,int n,int** outputArray){
    int i,j;
    outputArray=(int**)malloc(101*sizeof(int));
    for(i=0;i<101;i++){
        outputArray[i]=(int*)malloc(2*sizeof(int));
    }
    for(i=0;i<101;i++){
        for(j=0;j<2;j++){
            *outputArray[i]=i;
            *(outputArray[i]+1)=0;
        }
    }
    for(i=0;i<n;i++){
        *(outputArray[*(inputArray+i)]+1)+=1;
    }
    return outputArray;
}

int main(){
    int arr[1000],i,j;
    for(i=0;i<1000;i++){
        arr[i]=rand()%101;
    }
    int** oparray;
    oparray=findFreqDis(arr,1000,oparray);
    printf("Frequency Distribution:\n");
    for(i=0;i<101;i++){
        for(j=0;j<2;j++){
            printf("%d ",*(oparray[i]+j));
            if(j==0)printf("-> ");
        }
        printf("\n");
    }
    return 0;
}
