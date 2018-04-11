//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int ans[1000];
int cnt=0;
void solve(int n,int k,int index){
    /*
        if in last iteration n=7 and k=3 therefore (n-k)=4
        now we need to make a sum of 4 but last used denomination was 3 so we can't take directly 4
        if in last iteration n=7 and k=4 therefore (n-k)=3
        now we need to make a sum of 3 and last used denomination was 4 so we can't take 4 as it will exceed the sum
    */

    int i;
    if(n==0){
        for(i=0;i<index;i++){
            printf("%d ",ans[i]);
        }
        cnt++;
        printf("\n");
        return;
    }
    for(i=min(n,k);i>=1;i--){
        ans[index]=i;
        solve(n-i,i,index+1);
    }
}
int main(){
    int n;
    cin>>n;
    solve(n,n,0);
    cout<<"partition count="<<cnt<<"\n";
    return 0;
}
