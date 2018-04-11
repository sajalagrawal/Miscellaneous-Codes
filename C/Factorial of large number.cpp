//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ans="1";
ll len=1;
ll multiply(int x,int len){
    //cout<<"x="<<x<<endl;
    ll i,carry=0;
    for(i=0;i<len;i++){
        //cout<<"p ansi="<<ans[i]<<endl;
        ll prod=(ans[i]-'0')*x+carry;
        ans[i]='0'+prod%10;
        //cout<<"prod="<<prod<<endl;
        //cout<<"ansi="<<ans[i]<<endl;
        //cout<<"ans="<<ans<<endl;
        carry=prod/10;
    }
    while(carry){
        //ans[len++]='0'+carry%10;
        char ch='0'+carry%10;
        string num(1,ch);
        //cout<<"ch="<<ch<<endl;
        len++;
        ans.append(num);
        carry=carry/10;
    }
    //cout<<"len="<<len<<endl;
    return len;
}
void solve(){
    ll i;
    //n=10000000000
    // check = 10000
    for(i=2;i<=100;i++){
            //cout<<"ans="<<ans<<endl;
            len=multiply(i,len);
    }
}
int main()
{

    solve();
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
