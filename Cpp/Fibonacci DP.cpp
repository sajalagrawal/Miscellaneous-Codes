//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
unsigned ll fib[1000];

int main() {
    ll n;
    cin>>n;
    memset(fib,0,sizeof fib);
    fib[0]=0;
    fib[1]=fib[2]=1;
    int i=3;
    for(;i<=n;i++)fib[i]=fib[i-1]+fib[i-2];
    //for(i=0;i<=n;i++)
    cout<<fib[n]<<"\n";
	return 0;
}
