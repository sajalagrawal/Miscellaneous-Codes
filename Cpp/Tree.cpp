//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

//when tree is given in the form of two integers and one character 
//first of whose is parent node , second is child node and 
//character "L" representing Left child and "R" representing right child.

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}

void preOrderDisplay(Node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrderDisplay(r->left);
        preOrderDisplay(r->right);
    }
}

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        Node *root=NULL;
        while(n--){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
        preOrderDisplay(root);
    }
	return 0;
}
