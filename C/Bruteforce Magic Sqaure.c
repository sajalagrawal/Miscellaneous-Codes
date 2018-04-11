//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Bruteforce Magic Square

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
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
bool isMagicSquare(int n,int mat[][n]){
    //checking for unique elements
    int hash[n*n+1];
    int i,j;
    memset(hash,0,sizeof(hash));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)hash[mat[i][j]]++;
    }
    for(i=1;i<=n*n;i++){
        if(hash[i]!=1)return false;
    }
    ll sum=(n*(n*n+1))/2;
    //checking rowwise
    for(i=0;i<n;i++){
        ll rsum=0;
        for(j=0;j<n;j++)rsum+=mat[i][j];
        if(rsum!=sum)return false;
    }

    //checking colwise
    for(j=0;j<n;j++){
        ll csum=0;
        for(i=0;i<n;i++)csum+=mat[i][j];
        if(csum!=sum)return false;
    }

    //checking primary diagonal
    ll dsum=0;
    for(i=0;i<n;i++){
        dsum+=mat[i][i];
    }
    if(dsum!=sum)return false;

    ll sdsum=0;
    //checking secondary diagonal
    for(i=0;i<n;i++){
        j=n-1-i;
        sdsum+=mat[i][j];
    }
    if(sdsum!=sum)return false;
    return true;
}
void solve(int n,int mat[][n],int x,int y){
    //printf("x=%d y=%d\n",x,y);
    if(x>=n || y>=n){
        if(isMagicSquare(n,mat))
            printMatrix(n,mat);
        return ;
    }
    int i;
    int newx=x,newy=y;
    if(newy==n-1){
        newx++;
        newy=0;
    }else{
        newy++;
    }
    for(i=1;i<=n*n;i++){
        //printf("i=%d x=%d y=%d\n",i,x,y);
        //if(x==0 && y==0)
        mat[x][y]=i;
        solve(n,mat,newx,newy);
    }

}
int main(){
    //freopen("out.txt","w",stdout);
    int n=3;
    //printf("Enter n:");
    //scanf("%d",&n);
    int mat[n][n];
    solve(n,mat,0,0);
    return 0;
}
