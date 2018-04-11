//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
void printSubarray(int a[],bool subArray[],int n,int r){
    int i,count=0;
    for(i=0;i<n;i++){
        if(subArray[i])count++;
    }
    if(count!=r)return;
    for(i=0;i<n;i++){
        if(subArray[i])printf("%d ",a[i]);
    }
    printf("\n");
}

void generateComb(int a[],int index,int n,int r,bool subArray[]){
    //printf("index=%d",index);
    if(index>=n){
        printSubarray(a,subArray,n,r);
        return;
    }
    subArray[index]=0;
    generateComb(a,index+1,n,r,subArray);
    subArray[index]=1;
    generateComb(a,index+1,n,r,subArray);
}

int main()
{
    int n,r,i;
    printf("Enter n and r:");
    scanf("%d %d",&n,&r);
    printf("Enter n numbers:");
    int a[n];
    bool subArray[n];
    memset(subArray,0,sizeof(subArray));
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    generateComb(a,0,n,r,subArray);
    return 0;
}
