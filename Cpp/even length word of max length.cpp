//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007

int main() {
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int maxLen=-1;
        string str,token,ans;
        getline(cin,str);
        //cout<<"str="<<str<<endl;
        stringstream ss(str);
        while(ss>>token){
            //cout<<token.size()<<endl;
            //if(token.size()%2==0 and token.size()>maxLen)cout<<"this";
            
            if(token.size()%2==0 and (int)token.length()>maxLen){
                maxLen=token.size();
                ans=token;
            }
            //cout<<token.size()<<endl;
            //cout<<maxLen<<endl;
        }
        //cout<<maxLen<<endl;
        if(maxLen==-1)cout<<"00\n";
        else cout<<maxLen<<" "<<ans<<"\n";
    }
	return 0;
}
