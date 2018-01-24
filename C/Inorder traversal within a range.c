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
void rangeInorder(NODE* root,int x,int y){
    if(!root)return;
    if(root->data>=x && root->data<=y){
        rangeInorder(root->left,x,y);
        printf("%d ",root->data);
        rangeInorder(root->right,x,y);

    }
    if(root->data<x)rangeInorder(root->right,x,y);
    if(root->data>y)rangeInorder(root->left,x,y);
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
    printf("\n\nEnter x and y for inorder traversal:");
    scanf("%d %d",&x,&y);
    rangeInorder(root,x,y);
    return 0;
}
