/*
 * Median of randomly generated array.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include<stdio.h>
//function to swap 2 integers
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
float findMedian(int* inputArray,int n){
    int i;
    bubbleSort(inputArray,n);
    if(n&1)  // n is odd
        return (*(inputArray+n/2)+*(inputArray+n/2-1))/(float)2;
    return *(inputArray+n/2);
}
int main(){
    int arr[1000],i;
    for(i=0;i<1000;i++){
        arr[i]=rand()%101;
    }
    printf("Median:%f",findMedian(arr,1000));
    return 0;
}
