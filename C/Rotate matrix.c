//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
void rotateMatrix(int n,int a[n][n],int k){

    int i,j,iterate=n-2,rs=0,re=n-1,cs=0,ce=n-1,prev,cur;
    //rs=row start, re=row end, cs=col start, ce=col end
    while(k--){
        iterate=n-2,rs=0,re=n-1,cs=0,ce=n-1;
        while(iterate--){
            prev=a[rs+1][cs];
            for(i=cs;i<=ce;i++){
                cur=a[rs][i];
                a[rs][i]=prev;
                prev=cur;
            }
            rs++;
            for(i=rs;i<=re;i++){
                cur=a[i][ce];
                a[i][ce]=prev;
                prev=cur;
            }
            ce--;
            for(i=ce;i>=cs;i--){
                cur=a[re][i];
                a[re][i]=prev;
                prev=cur;
            }
            re--;
            for(i=re;i>=rs;i--){
                cur=a[i][cs];
                a[i][cs]=prev;
                prev=cur;
            }
            cs++;
    }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int n,i,j,k;
    printf("Enter N for NxN matrix:");
    scanf("%d",&n);
    printf("Enter matrix:\n");
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter rotation count:");
    scanf("%d",&k);
    rotateMatrix(n,a,k);
    return 0;
}
