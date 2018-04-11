//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
ll dp[1005][1005];

ll solve(int i,int j,int msize[]){
    if(i==j)return 0;
    if(dp[i][j]!=LLONG_MAX)return dp[i][j];
    int k;
    for(k=i;k<j;k++){
        //cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
        /*if(dp[i][j]==LLONG_MAX){
            dp[i][j]=solve(i,k,msize)+solve(k+1,j,msize)+msize[i-1]*msize[k]*msize[j];
        }else{*/
            dp[i][j]=min( dp[i][j], (solve(i,k,msize)+solve(k+1,j,msize)+msize[i-1]*msize[k]*msize[j]) );
        //}
    }
    return dp[i][j];
}

int main() {
    ll n,i,j;
    cin>>n;
    int msize[n+1];
    for(i=0;i<=n;i++)cin>>msize[i];
    for(i=0;i<1005;i++){
        for(j=0;j<1005;j++){
            dp[i][j]=LLONG_MAX;
        }
    }
    //cout<<"here";
    cout<<solve(1,n,msize);
	return 0;
}
