/*
 * All permutations of a number in sorted order.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include <stdio.h>
#include <string.h>
void swap(char* a,char* b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(char arr[],int start,int n){
   int i, j,k;
   for (i = start,k=0; i < n-1; i++,k++)
       // Last k elements are already in place
       for (j = start; j < n-k-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
       }
}

int findNext(char num[]){
    int n=strlen(num);
    int i,j;
    for(i=n-1;i>0;i--){
        if(num[i]>num[i-1])break;
    }
    if(i==0){
        return 0;
    }
    int x=num[i-1],smallest=num[i],index=i,start=i;
    for(j=i+1;j<n;j++){
        if(num[j]>x && num[j]<smallest){
            smallest=num[j];
            index=j;
        }
    }
    swap(&num[i-1],&num[index]);
    bubbleSort(num,start,n);
    printf("%s\n",num);
    return 1;
}

int main(void) {
    char num[20];
    printf("Enter num:");
    scanf("%s",num);
    bubbleSort(num,0,strlen(num));
    printf("All permutations-\n%s\n",num);
    while(findNext(num));
	return 0;
}
