//Author - Sajal Agrawal
//@sajal.agrawal1997@gmail.com

//https://stackoverflow.com/questions/14887433/trie-implementation-with-map
//http://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
struct Node{
    map<char, Node*> mp;
    bool endOfWord;
    
    Node(){
        endOfWord=false;
    }
};
void insert(Node *head,string str){
    Node *cur=head;
    for(int i=0;i<str.size();i++){
        if(cur->mp.count(str[i])==0){
            cur->mp[str[i]]=new Node;
        }
        cur=cur->mp[str[i]];
    }
    cur->endOfWord = true;
}

bool search(Node* head, string str){

    if(head==NULL){
        return false;
    }
    Node *cur=head;
    for(int i=0;i<str.size();i++){
        cur=cur->mp[str[i]];
        if(cur==NULL)
            return false;
    }
    return cur->endOfWord;
}

int main() {
    Node *head=new Node;
    insert(head,"hello");
    insert(head,"hey");
    cout<<search(head,"hello")<<"\n";
    cout<<search(head,"hell")<<"\n";
    insert(head,"hell");
    cout<<search(head,"helloy")<<"\n";
    cout<<search(head,"xyz")<<"\n";
    cout<<search(head,"hey")<<"\n";
    cout<<search(head,"hell")<<"\n";
	return 0;
}
