//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com


#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node NODE;
NODE* root=NULL;
int count=0;

NODE *lowestCommonAncestor(int x,int y,NODE *root){
	if(root->data<x)return lowestCommonAncestor(x,y,root->right);
	if(root->data>y)return lowestCommonAncestor(x,y,root->left);
	return root;
}
NODE* insert(NODE* r,int n){
    if(r==NULL){
        r=(NODE*)malloc(sizeof(NODE));
        r->left=r->right=NULL;
        r->data=n;
        //printf("added:%d\n",r->data);
    }else{
        if(r->data > n){
            r->left=insert(r->left,n);
        }else{
            r->right=insert(r->right,n);
        }
    }
    return r;
}
void inorderDisplay(NODE *r){
    if(r!=NULL){
        inorderDisplay(r->left);
        printf("%d ",r->data);
        inorderDisplay(r->right);
    }
}
int search(NODE *r,int num){
    if(r==NULL){
        return 0;
    }else if(r->data==num){
        return 1+search(r->right,num);
    }else if(num < r->data){
        return search(r->left,num);
    }else{
        return search(r->right,num);
    }
}
int main()
{
    int n,k,i,num,x,y;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    printf("Enter nodes:\n");
    for(i=0;i<n;i++){
        scanf("%d",&k);
        root=insert(root,k);
    }
    printf("Inorder:\n");
    inorderDisplay(root);
    printf("Enter x and y:");
    scanf("%d %d",&x,&y);
    NODE* res=lowestCommonAncestor(x,y,root);
    printf("lca: %d\n",res->data);
    return 0;
}
