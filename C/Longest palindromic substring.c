//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    printf("Enter str:");
    scanf("%s",str);
    int maxLen=0,dp[100][100]={0},i=0,start=0,end=0,n=0;
    while(str[i++]!='\0')n++;
    //printf("n=%d\n",n);
    for(i=0;i<n;i++)dp[i][i]=1;
    maxLen=1;
    for(i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=1;
            start=i;
            end=i+1;
            maxLen=2;
        }
    }
    int k=3,j;
    for(;k<=n;k++){
        //printf("k=%d\n",k);
        for(i=0;i<=n-k;i++){
            j=i+k-1;
            //printf("i=%d j=%d\n",i,j);
            if(dp[i+1][j-1] && str[i]==str[j]){
                dp[i][j]=1;
                maxLen=k;
                start=i;
                end=j;
            }
        }
    }
    printf("Max palindromic length:%d\nString:",maxLen);
    for(i=start;i<=end;i++)printf("%c",str[i]);
    return 0;
}
