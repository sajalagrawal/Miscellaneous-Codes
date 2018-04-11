//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
ll price[1005];
bool solved[1005];
ll solve(ll n){
    if(solved[n]==true)return price[n];
    int i=1;
    for(;i<=n/2;i++){
        price[n]=max( (solve(i)+solve(n-i)), price[n] );
    }
    solved[n]=true;
    return price[n];
}

int main(){
    ll n,i;
    cin>>n;
    memset(price,0,sizeof price);
    memset(solved,0,sizeof solved);
    for(i=1;i<=n;i++)cin>>price[i];
    cout<<solve(n)<<"\n";
	return 0;
}
