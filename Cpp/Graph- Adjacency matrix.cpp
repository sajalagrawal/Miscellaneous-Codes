/*
Program for creation of adjacency matrix.
Author- SAJAL AGRAWAL
sajal.agrawal1997@gmail.com
*/
#include <iostream>
using namespace std;
#define MAX 100
int adj[MAX][MAX];
int n;

int main() {
	// your code goes here
	int graphType,maxEdges,i,j,orig,des;
	cout<<"Enter 1 for undirected graph and 2 for directed graph:";
	cin>>graphType;
	cout<<"Enter number of vertices:";
	cin>>n;
	if(graphType==1)
	    maxEdges=n*(n-1)/2;
	else
	    maxEdges=n*(n-1);
	cout<<"Enter edges::(0 base indexing..)\n";
	for(i=0;i<maxEdges;i++){
	    cout<<"Enter edge "<<i<<" (-1 -1) to quit.";
	    cin>>orig>>des;
	    if(orig==-1 and des==-1)break;
	    else if(orig>=n or des>=n or orig<0 or des<0){
	        cout<<"Invalid i/p.\n";
	    }
	    else {
	        adj[orig][des]=1;
	        if(graphType==1)adj[des][orig]=1;
	    }
	}
	cout<<"The adjacency matrix is:\n";
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        cout<<adj[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}


