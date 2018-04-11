//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Backtracking- generate min heap

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<stdbool.h>
bool checkIfMinHeap(int size,int heap[size]){
    int parent=-1,i;
    for(i=0;i<size;i++){
        if(i>=1)parent=heap[(i-1)/2];
        if(heap[i]<parent)return false;
    }
    return true;
}
void printHeap(int size,int heap[size]){
    int i,level=0,count=0;
    //printf("\nprint heap\n");
    for(i=0;i<size;i++){
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
int unoccupied(int size,int occupied[size],int idx){
    int i,count=0;
    for(i=idx+1;i<size;i++){
        if(occupied[i]==0)count++;
    }
    return count;
}
void solve(int n,int size,int heap[size],int occupied[size],int cell){
    if(cell>=size){
        /*this algo doesn't guarantee that all the heaps generated will be min-heap,
        hence at the end we need to check whether the generated heap is a min heap */
        if(checkIfMinHeap(size,heap))
            printHeap(size,heap);
        //printf("ending at cell %d\n",cell);
        return;
    }
    int i;
    int level=log(cell+1)/log(2); //assuming: levels starts from 0 not 1
    //printf("cell=%d and level=%d\n",cell,level);
    for(i=0;i<size;i++){
        if(occupied[i]==0){
            int eleInSubtree=pow(2,n-level)-2;
            //if(cell==0)printf("i=%d required below:%d\n",i,eleInSubtree);
            int largerUnoccupied=unoccupied(size,occupied,i);
            //if(cell==0)printf("actually present:%d\n",largerUnoccupied);
            if(largerUnoccupied>=eleInSubtree){
                heap[cell]=i+1;
                occupied[i]=1;
                solve(n,size,heap,occupied,cell+1);
                heap[cell]=0;
                occupied[i]=0;
            }
        }
    }
    return;
}

int main(){
    //freopen("opbt.txt","w",stdout);
    int n;
    printf("Enter n for 2^n-1: ");
    scanf("%d",&n);
    int size=pow(2,n)-1;
    int occupied[size];
    int heap[size];
    memset(heap,0,sizeof(heap));
    memset(occupied,0,sizeof(occupied));
    solve(n,size,heap,occupied,0);
    return 0;
}
