//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Backtracking in N-Queens such that no 3 queens are in a line

#include<stdio.h>
#include<stdbool.h>
#include <string.h>

bool isPossible(int n,int mat[][n],int x,int y){
    //printf("x=%d y=%d\n",x,y);
    if(x==0)return true;
    int row,col;
    for(row=0;row<x;row++){
        for(col=0;col<n;col++){
            if(mat[row][col]==1){
                //printf("1 at x=%d y=%d\n",x,y);
                if(y==col)return false;
                if((row+col)==(x+y)){
                    //printf("bug row+col\n");
                    return false;
                }
                int sum1=row+col,sum2=x+y;
                if(sum2==(sum1+2*(x-row))){
                    //printf("bug sum1=%d sum2=%d row=%d col=%d\n",sum1,sum2,row,col);
                    return false;
                }
            }

        }
    }

    //checking 3 queens in a line
    int q1row=-1,q1col=-1,q2row=-1,q2col=-1,row2,col2;
    for(row=0;row<x;row++){
        for(col=0;col<n;col++){
            if(mat[row][col]==1){
                q1row=row;
                q1col=col;
                for(row2=0;row2<x;row2++){
                    for(col2=0;col2<n;col2++){
                        if(mat[row2][col2]==1){
                             q2row=row2;
                             q2col=col2;
                             if(q1row!=q2row && q1col!=q2col){
                                if( ( (q1col-y)*(q1row-q2row) ) == ( (q1row-x)*(q1col-q2col) ) )return false;
                             }
                        }
                    }
                }
            }
        }
    }

    //printf("allowed x=%d y=%d\n",x,y);
    return true;
}

void nQueens(int n,int mat[][n],int qcount){
    int i,j,k;
    //printf("qCount=%d\n",qcount);
    if(qcount==n){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                //cout<<mat[][]<<" ";
                printf("%d ",mat[i][j]);
            }
            //cout<<"\n";
            printf("\n");
        }
        printf("\n");
    }
    for(i=0;i<n;i++){

        //if(qcount==2)printf("i=%d\n",i);
        if( isPossible(n,mat,qcount,i)==true ){
            //printf("put at x=%d y=%d\n",qcount,i);
            mat[qcount][i]=1;
            nQueens(n,mat,qcount+1);
            //printf("bt\n");
            /*for(j=qcount;j<n;j++){
                for(k=0;k<n;k++)mat[j][k]=0;
            }*/
            //after backtracking, put 0 again on the accepted position
            mat[qcount][i]=0;
        }
    }
    return;
}
main(){
    //freopen("queen3.txt","w",stdout);
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int mat[n][n];
    memset(mat,0,sizeof(mat));
    nQueens(n,mat,0);
}
