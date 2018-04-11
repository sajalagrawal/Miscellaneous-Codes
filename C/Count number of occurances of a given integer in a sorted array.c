//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
int firstOccurence(int a[],int low,int high,int x){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==x && (mid==0 || a[mid-1]<x ))return mid;
        else if(x>a[mid]) return firstOccurence(a,mid+1,high,x);
        else return firstOccurence(a,low,mid-1,x);
    }
    return -1;
}
int lastOccurence(int a[],int low,int high,int x,int n){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid]==x && (mid==n-1 || a[mid+1]>x))return mid;
        else if(a[mid]>x)return lastOccurence(a,low,mid-1,x,n);
        else return lastOccurence(a,mid+1,high,x,n);
    }
    return -1;
}
int solve(int a[],int n,int x){
    int first,second;
    first=firstOccurence(a,0,n-1,x);
    if(first==-1)return 0;
    second=lastOccurence(a,first,n-1,x,n);

    printf("i=%d j=%d\n",first,second);
    return (second-first+1);
}


int main(){
    int n,i,x;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter element to be searched:");
    scanf("%d",&x);
    printf("Count=%d",solve(a,n,x));
    return 0;
}
