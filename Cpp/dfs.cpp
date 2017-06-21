//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[100005];
vector<ll> visited(100005);
vector<ll> height(100005);
void dfs(ll root){
    queue<ll> q;
    q.push(root);
    visited[root]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(ll i=0;i<v[p].size();i++){
            if(visited[v[p][i]]==0){
                q.push(v[p][i]);
                visited[v[p][i]]=1;
                height[v[p][i]]=height[p]+1;   //also storing level of each node, level of root node=0
            }
        }
    }
}
