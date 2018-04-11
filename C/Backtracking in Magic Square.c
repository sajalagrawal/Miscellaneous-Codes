//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Backtracking in Magic Square

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define ll long long
#define finalSum (n*(n*n+1))/2
bool isMagicSquare(int n,int mat[][n]){
    int i,j;
    //checking for unique elements
    /*int hash[n*n+1];
    memset(hash,0,sizeof(hash));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)hash[mat[i][j]]++;
    }
    for(i=1;i<=n*n;i++){
        if(hash[i]!=1)return false;
    }*/
    //ll finalSum=(n*(n*n+1))/2;
    //checking rowwise
    for(i=0;i<n;i++){
        ll rsum=0;
        for(j=0;j<n;j++)rsum+=mat[i][j];
        if(rsum!=finalSum)return false;
    }

    //checking colwise
    for(j=0;j<n;j++){
        ll csum=0;
        for(i=0;i<n;i++)csum+=mat[i][j];
        if(csum!=finalSum)return false;
    }

    //checking primary diagonal
    ll dsum=0;
    for(i=0;i<n;i++){
        dsum+=mat[i][i];
    }
    if(dsum!=finalSum)return false;

    ll sdsum=0;
    //checking secondary diagonal
    for(i=0;i<n;i++){
        j=n-1-i;
        sdsum+=mat[i][j];
    }
    if(sdsum!=finalSum)return false;
    return true;
}
void printMatrix(int n,int mat[][n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void magicSquare(int n,int mat[n][n],bool occupied[],int cellCount){
    if(cellCount>=n*n){
        if(isMagicSquare(n,mat)){
            printMatrix(n,mat);
        }
        return;
    }
    int i,j,k,rsum=0,csum=0;
    int row=cellCount/n;
    int col=cellCount%n;
    for(i=1;i<=n*n;i++){
        if(occupied[i-1]==false){
            //Heuristic 1
            //checking last row just before previous current if they satisfy the required finalSum
            if(row>=1){
                rsum=0;
                for(k=0;k<n;k++){
                    rsum+=mat[row-1][k];
                }
                if(rsum!=finalSum)goto bt;
            }

            ////Heuristic 2
            //if currently at last row check all col sum if satisfying the req finalSum
            if(row==n-1 && col>0){
                for(j=0;j<col;j++){
                    csum=0;
                    for(k=0;k<n;k++){
                        csum+=mat[k][j];
                    }
                    if(csum!=finalSum)goto bt;
                }
            }

            //Heuristic 3
            //checking if the remaining cells can make up a sum of required finalSum
            int curSum=0;
            for(j=0;j<col;j++)curSum+=mat[row][j];
            //printMatrix(n,mat);
            int maxRightSum=0,count=0;
            for(j=n*n-1;j>=0;j--){
                if(count>=(n-col))break;
                if(occupied[j]==false){
                    maxRightSum+=j+1;
                    count++;
                }
            }
            //printf("cursum=%d maxRightSum=%d finalSum=%d\n\n\n",curSum,maxRightSum,finalSum);
            if( (curSum + maxRightSum) < finalSum )goto bt;

            //Heuristic 4
            //checking if the remaining cells can make up a sum of required finalSum columnwise
            curSum=0;
            for(j=0;j<row;j++)curSum+=mat[j][col];
            int maxDownSum=0;
            count=0;
            for(j=n*n-1;j>=0;j--){
                if(count>=(n-row))break;
                if(occupied[j]==false){
                    maxDownSum+=j+1;
                    count++;
                }
            }
            if( (curSum + maxDownSum) < finalSum )goto bt;

            mat[row][col]=i;

            //Heuristic 5
            //checking if the remaining cells can make up a sum of required finalSum diagonalwise- primary diagonal
            curSum=0;
            if(row>col)for(j=0;j<row;j++)curSum+=mat[j][j];
            if(row<=col)for(j=0;j<=row;j++)curSum+=mat[j][j];
            int maxPrimaryDiagonalSum=0;
            count=0;
            for(j=n*n-1;j>=0;j--){
                if(row>col){
                    if(count>=(n-row+1))break;
                }else{
                    if(count>=(n-row))break;
                }
                if(occupied[j]==false){
                    maxPrimaryDiagonalSum+=j+1;
                    count++;
                }
            }
            if( (curSum + maxPrimaryDiagonalSum) < finalSum )goto bt;

            occupied[i-1]=true;
            magicSquare(n,mat,occupied,cellCount+1);
            bt:;
            occupied[i-1]=false;
            mat[row][col]=0;
        }
    }
}
int main(){
    //freopen("out.txt","w",stdout);
    int n=5;
    //1print1f("Enter n:");
    //scanf("%d",&n);
    int mat[n][n];
    bool occupied[n*n];
    memset(occupied,false,sizeof(occupied));
    memset(mat,0,sizeof(mat[0][0])*n*n);
    magicSquare(n,mat,occupied,0);
    return 0;
}
