//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Backtracking in Sudoku
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
bool isSolution(int n,int mat[][n]){
    //printf("in is sol");
    int i,j,k;
    //checking each row
    for(i=0;i<n;i++){
        int hash[n+1];
        memset(hash,0,sizeof(hash));
        for(j=0;j<n;j++){
            hash[mat[i][j]]++;
        }
        for(j=1;j<=n;j++){
            if(hash[j]!=1)return false;
        }
    }
    //printf("row done");
    //checking each col
    for(j=0;j<n;j++){
        int hash[n+1];
        memset(hash,0,sizeof(hash));
        for(i=0;i<n;i++){
            hash[mat[i][j]]++;
        }
        for(i=1;i<=n;i++){
            if(hash[i]!=1)return false;
        }
    }
    int size=sqrt(n); //size of each block
    //checking each block
    for(k=1;k<=n;k++){  //kth block- there are n blocks in total
        //printf("k=%d\n",k);
        i=((k-1)/size)*size;
        if(k%size==0) j=(size-1)*size;
        else j=(k%size-1)*size;
        int tempj=j;
        int iend=i+size;
        int jend=j+size;
        int hash[n+1];
        //printf("istart=%d iend=%d jstart=%d jend=%d\n",i,iend,j,jend);
        memset(hash,0,sizeof(hash));
        for(;i<iend;i++){
            j=tempj;
            for(j=tempj;j<jend;j++){
                hash[mat[i][j]]++;
            }
        }
        //for(j=1;j<=n;j++)printf("%d ",hash[j]);
        //printf("\n");
        for(i=1;i<=n;i++){
            if(hash[i]!=1)return false;
        }
    }
    return true;
}

bool canPlaceI(int n,int mat[][n],int cell,int val){
    int row=cell/n;
    int col=cell%n;
    int i,j;
    //check row
    for(i=0;i<n;i++){
        if(mat[row][i]==val)return false;
    }

    //check col
    for(i=0;i<n;i++){
        if(mat[i][col]==val)return false;
    }

    //check block
    int startrow=(row/sqrt(n));
	startrow*=sqrt(n);
    int startcol=(col/sqrt(n));
	startcol*=sqrt(n);
    //printf("row=%d col=%d startrow=%d startcol=%d\n",row,col,startrow,startcol);
    int endrow=startrow+sqrt(n)-1;
    int endcol=startcol+sqrt(n)-1;
    for(i=startrow;i<=endrow;i++){
        for(j=startcol;j<=endcol;j++){
            if(mat[i][j]==val)return false;
        }
    }

    //else
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

void solve(int n,int mat[][n],int cell){
    //printf("cell=%d n=%d\n",cell,n);
    if(cell>=n*n){
        //printMatrix(n,mat);
        if(isSolution(n,mat)){
            printMatrix(n,mat);
        }
        return;
    }
    int i;
    int row=cell/n;
    int col=cell%n;
    if(mat[row][col]==-1){
        for(i=1;i<=n;i++){
            //printf("i=%d\n",i);
            if( canPlaceI(n,mat,cell,i)==true ){
                //printf("can place i=%d\n",i);
                mat[row][col]=i;
                solve(n,mat,cell+1);
                mat[row][col]=-1;
            }
        }
    }else{
        solve(n,mat,cell+1);
    }
}
int main(){
    int n,i,j;
    //freopen("out.txt","w",stdout);
    //printf("Enter n:");
    //scanf("%d",&n);
    /*int mat[n][n];
    printf("Enter matrix[][] -1 to enter blank place");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)scanf("%d",&mat[i][j]);
    }*/
    n=9;
    int mat[9][9]={
        {-1,-1,2,9,-1,5,8,-1,3},
        {3,9,-1,-1,-1,-1,-1,6,4},
        {-1,-1,1,-1,-1,-1,9,-1,-1},
        {-1,-1,-1,5,-1,1,-1,-1,-1},
        {-1,4,-1,6,-1,2,-1,3,-1},
        {-1,-1,-1,4,-1,8,-1,-1,-1},
        {-1,-1,7,-1,-1,-1,5,-1,-1},
        {5,1,-1,-1,-1,-1,-1,2,7},
        {9,-1,4,7,-1,3,6,-1,8},
    };
    /*n=4;
    int mat[4][4]={{1,4,3,2},{3,-1,4,-1},{-1,1,-1,3},{2,3,1,4}};
        */
    /*n=4;
    int mat[4][4]={{-1,-1,-1,-1},
                   {-1,-1,-1,-1},
                   {1,2,3,4},
                   {-1,-1,-1,-1}};
    //printMatrix(n,mat);
*/
    solve(n,mat,0);
    return 0;
}

