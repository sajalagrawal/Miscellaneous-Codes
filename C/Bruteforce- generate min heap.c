//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Bruteforce- generate min heap

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool checkIfMinHeap(int n,int heap[n]){
    int parent=-1,i;
    for(i=0;i<n;i++){
        if(i>=1)parent=heap[(i-1)/2];
        if(heap[i]<parent)return false;
    }
    return true;
}
void printHeap(int n,int heap[n]){
    int i,level=0,count=0;
    //printf("\nprint heap\n");
    for(i=0;i<n;i++){
        printf("%d ",heap[i]);
        count++;
        if(count==pow(2,level)){
            level++;
            count=0;
            printf("\n");
        }
    }
    printf("\n");
}
void solve(int n,int heap[n],int occupied[n],int cell){
    //printf("\ncell=%d n=%d\n",cell,n);
    if(cell>=n){
        //printf("cell>=n\n");
        if(checkIfMinHeap(n,heap)){
                //printf("is heap\n");
                printHeap(n,heap);
        }
        return;
    }
    int i,j;
    for(i=0;i<n;i++){
        //printf("%d ",i);
        //printf("cell=%d i=%d\n ",cell,i);
        //for(j=0;j<n;j++)printf("%d ",occupied[j]);
        //printf("\n");
        if(occupied[i]==0){
            //printf("inside if cell=%d i=%d\n ",cell,i);
            occupied[i]=1;
            heap[cell]=i+1;
            //printf("%d",i+1);
            solve(n,heap,occupied,cell+1);
            heap[cell]=0;
            occupied[i]=0;
        }
    }
}
int main(){
    //freopen("opbrute.txt","w",stdout);
    int n,i,j;
    printf("Enter n:");
    scanf("%d",&n);
    int heap[n];
    memset(heap,0,sizeof(heap));
    int occupied[n];
    memset(occupied,0,sizeof(occupied));
    solve(n,heap,occupied,0);
    return 0;
}
