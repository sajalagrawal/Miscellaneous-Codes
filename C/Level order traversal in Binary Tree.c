//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define ll long long
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node NODE;
NODE* root=NULL;
int previous=INT_MIN;
int max(int a,int b){
    return a>b?a:b;
}
void insert(NODE *root,int a,int b,char ch){
    //printf("a=%d b=%d ch=%c\n",a,b,ch);
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L'://root->left=new Node(b);
                    root->left=(NODE*)malloc(sizeof(NODE));
                    root->left->data=b;
                    root->left->left=root->left->right=NULL;
                    break;
            case 'R'://root->right=new Node(b);
                    root->right=(NODE*)malloc(sizeof(NODE));
                    root->right->data=b;
                    root->right->left=root->right->right=NULL;
                    break;
        }
        return;
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}
int height(NODE* root){
    if(!root)return 0;
    return 1+max(height(root->left),height(root->right));
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
    }
    //printf("cur=%d\n",r->data);
    if(r->data==num)return 1;
    return max(search(r->left,num),search(r->right,num));
}
void printLevelOrder(NODE* root){
    int i;
    for(i=1;i<=height(root);i++){
        printLevel(root,i);
    }
}

void printLevel(NODE* root,int i){
    if(root==NULL)return;
    if(i==1)printf("%d ",root->data);
    else{
        printLevel(root->left,i-1);
        printLevel(root->right,i-1);
    }
}
int main()
{
    int n,k,i,num;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    n--;
    printf("Enter nodes:\n");
    for(i=0;i<n;i++){
        int a,b;
        char ch;
        scanf("%d %d",&a,&b);
        scanf(" %c",&ch);
        if(root==NULL){
            //printf("a=%d b=%d ch=%c\n",a,b,ch);
            //root=new Node(a);
            root=(NODE*)malloc(sizeof(NODE));
            root->data=a;
            root->left=root->right=NULL;
            switch(ch){
                case 'L'://root->left=new Node(b);
                        root->left=(NODE*)malloc(sizeof(NODE));
                        root->left->data=b;
                        root->left->left=root->left->right=NULL;
                        break;
                case 'R'://root->right=new Node(b);
                        root->right=(NODE*)malloc(sizeof(NODE));
                        root->right->data=b;
                        root->right->left=root->right->right=NULL;
                        break;
            }
        }else{
            insert(root,a,b,ch);
        }
    }
    printf("Inorder:\n");
    inorderDisplay(root);
    printf("\n\nLevel order:\n");
    printLevelOrder(root);
    return 0;
}
