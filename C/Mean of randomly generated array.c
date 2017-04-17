/*
 * Mean of randomly generated array.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include<stdio.h>
float findMean(int* inputArray,int n){
    int i,sum=0;
    for(i=0;i<1000;i++)
        printf("%d ",*(inputArray+i));
    for(i=0;i<1000;i++)sum+= *(inputArray+i);
    //printf("\nsum=%d\nn=%d\n",sum,n);
    return ((float)sum/n);
}
int main(){
    int arr[1000],i;
    for(i=0;i<1000;i++){
        arr[i]=rand()%101;
    }
    /*for(i=0;i<1000;i++)
        printf("%d ",arr[i]);*/
    printf("\nMean:%f",findMean(arr,1000));
    return 0;
}
