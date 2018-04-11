//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back

int main() {
    int n,w,i,j;
    cin>>n;
    int values[n];
    int weights[n];
    for(i=0;i<n;i++)cin>>values[i];
    for(i=0;i<n;i++)cin>>weights[i];
    cin>>w;
    int dp[n][w+1];
    memset(dp,0,sizeof(dp));
    /*for(i=0;i<n;i++){
        for(j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<=w;j++){
            if(j<weights[i]){
                if(i>0)dp[i][j]=dp[i-1][j];
                else dp[i][j]=0;
            }else{
                if(i>0)dp[i][j]=max( dp[i-1][j], values[i]+dp[i-1][j-weights[i]] );
                else dp[i][j]=values[i];
                //cout<<"i="<<i<<" j="<<j<<" dp="<<dp[i][j]<<endl;
            }
        }
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n-1][w]<<"\n";
	return 0;
}
