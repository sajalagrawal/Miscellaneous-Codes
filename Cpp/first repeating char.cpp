//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007

int main() {
    string str="cbaabc";
    int i,index=INT_MAX;
    map<char,int> mp;   //char, index
    for(i=0;i<str.size();i++){
        if(mp.find(str[i])!=mp.end()){
            cout<<"i="<<i<<endl;
            cout<<"mp[]="<<mp[str[i]]<<endl;
            index=min(index,mp[str[i]]);
        }else{
            mp[str[i]]=i;    
        }
    }
    if(index>str.size())index=-1;
    cout<<index<<endl;
	return 0;
}
