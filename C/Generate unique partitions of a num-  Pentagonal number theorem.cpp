//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

//Partition numbers
//https://www.youtube.com/watch?v=aj4FozCSg8g
//https://en.wikipedia.org/wiki/Pentagonal_number_theorem
//https://en.wikipedia.org/wiki/Partition_(number_theory)

#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> dp;
ll pentagonal(ll n){
    return (n*(3*n-1))/2;
}
ll solve(ll n){
    if(n<0)return 0;
    if(n<=1)return dp[n];
    if(dp[n]!=0)return dp[n];
    ll k;
    for(k=1;;k++){
        ll pent=pentagonal(k);
        //cout<<"k="<<k<<" pent(k)="<<pent<<endl;
        if(pent<=n)dp[n]=dp[n]+pow(-1,k-1)*solve(n-pent);
        else break;
        k=-k;
        pent=pentagonal(k);
        //cout<<"k="<<k<<" pent(k)="<<pent<<endl;
        if(pent<=n)dp[n]=dp[n]+pow(-1,k-1)*solve(n-pent);
        else break;
        k=-k;
    }
    return dp[n];
}

int main(){
    ll n;
    dp[0]=dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    printf("Enter n:");
    scanf("%lld",&n);
    for(n=0;n<20;n++)
    printf("n=%lld and count=%lld\n",n,solve(n)-1);
    return 0;
}
