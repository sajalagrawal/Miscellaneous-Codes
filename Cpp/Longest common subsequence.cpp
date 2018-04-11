//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long

static int dp[5001][5001];
int main() {
    ll t,i,j;
    t=1;
    while(t--){
        ll m,n;
        string s1,s2;
        cin>>s1>>s2;
        m=s1.size();
        n=s2.size();
        string res="";
        for(i=0;i<=m;i++)dp[i][0]=0;
        for(i=0;i<=n;i++)dp[0][i]=0;

        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        i=m;
        j=n;
        while(dp[i][j]!=0){  //i>0 and j>0
            if(s1[i-1]==s2[j-1]){
                res+=s1[i-1];
                i--;j--;
            }else{
				if (dp[i-1][j] > dp[i][j-1])
					 i--;
				else
					 j--;
            }
        }
        reverse(res.begin(),res.end());
        cout<<dp[m][n]<<"\n"<<res<<"\n";
    }
	return 0;
}
