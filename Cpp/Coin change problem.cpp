//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll m,n,i,j;
    cin>>m;
    ll coins[m];
    for(i=0;i<m;i++)cin>>coins[i];
    cin>>n;
    ll dp[n+1];
    for(i=0;i<=n;i++)dp[i]=INT_MAX;
    dp[0]=0;
    for(i=0;i<m;i++){
        //for each coin
        for(j=coins[i];j<=n;j++){
            dp[j]=min( dp[j] , ( 1+dp[j-coins[i]] ) );
        }
    }
    cout<<dp[n]<<"\n";
	return 0;
}
