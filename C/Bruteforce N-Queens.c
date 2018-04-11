//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Bruteforce N-Queens

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool isValidSetup(int n,int mat[][n]){
    //one queen per row
    int i,j,count=0,row,col;
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(mat[i][j])count++;
        }
        if(count!=1)return false;
    }
    //one queen per column
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(mat[j][i])count++;
        }
        if(count!=1)return false;
    }
    //one primary diagonal
    count=0;
    for(i=0;i<n;i++){
        if(mat[i][i])count++;
    }
    if(count>1)return false;

    //checking lower triangle- primary diagonal
    for(i=1;i<n;i++){
        row=i;
        col=0;
        count=0;
        while(row!=n){
            if(mat[row][col])count++;
            row++;
            col++;
        }
        if(count>1)return false;
    }

    //checking upper triangle- all indices of mirror image- primary diagonal
    for(i=1;i<n;i++){
        row=i;
        col=0;
        count=0;
        while(row!=n){
            if(mat[col][row])count++;
            row++;
            col++;
        }
        if(count>1)return false;
    }

    //one secondary diagonal
    count=0;
    for(i=0;i<n;i++){
        if(mat[i][n-1-i])count++;
    }
    if(count>1)return false;

    //checking upper triangle- secondary diagonal
    for(i=0;i<n-1;i++){  //i is for column
        row=0;
        col=i;
        count=0;
        while(col!=-1){
            if(mat[row][col])count++;
            row++;
            col--;
        }
        if(count>1)return false;
    }

    //checking lower triangle- secondary diagonal- this time there are no mirror images
    for(i=1;i<=n-1;i++){ //i is for row
        row=i;
        col=n-1;
        count=0;
        while(row!=n){
            if(mat[row][col])count++;
            row++;
            col--;
        }
        if(count>1)return false;
    }
    return true;
}
void nQueens(int n,int mat[][n],int qCount,int cell){
    int i,j,k;
    if(qCount>n){
        if(isValidSetup(n,mat)){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%d ",mat[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        return;
    }
    i=cell;
    int row=cell/n;
    int col=cell%n;
    for(;i<=(n*n-n-1+qCount);i++){
        cell=i;
        row=cell/n;
        col=cell%n;
        mat[row][col]=qCount;
        nQueens(n,mat,qCount+1,cell+1);
        mat[row][col]=0;
    }
    return;
}
int main(){
    //freopen("op.txt","w",stdout);
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int mat[n][n];
    memset(mat,0,sizeof(mat[0][0])*n*n);
    nQueens(n,mat,1,0);  //placing 1st queen
    return 0;
}
