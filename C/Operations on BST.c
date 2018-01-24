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
void inorderDisplay(NODE *r){
    if(r!=NULL){
        inorderDisplay(r->left);
        printf("%d ",r->data);
        inorderDisplay(r->right);
    }
}
void preorderDisplay(NODE *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preorderDisplay(r->left);
        preorderDisplay(r->right);
    }
}

void postorderDisplay(NODE *r){
    if(r!=NULL){
        postorderDisplay(r->left);
        postorderDisplay(r->right);
        printf("%d ",r->data);
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

bool solve(NODE *r){
    if(r!=NULL){

        if(solve(r->left)==false)return false;
        ///cout<<"r->data"<<r->data<<" prev="<<previous<<endl;
        if((r->data)<previous){
            //cout<<r->data<<endl;
            return false;
        }
        else{
            previous=r->data;
            //cout<<"prev="<<previous<<endl;
        }
        if(solve(r->right)==false)return false;
    }
    return true;
}
int height(NODE* root){
    if(!root)return 0;
    return 1+max(height(root->left),height(root->right));
}
void printPath(NODE* root,int x){
    if(root==NULL)return ;
    if(root->data==x){
        printf("%d \n\n",x);
        return;
    }
    if(search(root,x)){
        printf("%d ->",root->data);
    }
    printPath(root->left,x);
    printPath(root->right,x);
}
int countNodes(NODE* root){
    if(!root)return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int sumOfAllNodes(NODE* root){
    if(!root)return 0;
    return root->data+sumOfAllNodes(root->left)+sumOfAllNodes(root->right);
}
void traversal(NODE* root,int trav){
    if(trav==0){
        preorderDisplay(root);
    }else if(trav==1){
        inorderDisplay(root);
    }else if(trav==2){
        postorderDisplay(root);
    }else{
        return;
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
    if(solve(root)){
        printf("\nIS BST\n");
    }else{
        printf("\nIS NOT BST\n");
    }
    printf("Height of given tree: %d\n",height(root));
    printf("Enter number to be searched:");
    scanf("%d",&num);
    if(search(root,num))printf("Found\n");
    else printf("Not found\n");
    int x;
    printf("Enter node for printing path from root to node:");
    scanf("%d",&x);
    if(search(root,x)){
        printPath(root,x);
    }else{
        printf("%d is not present in the tree.\n\n",x);
    }
    printf("count of nodes: %d\n",countNodes(root));
    printf("Sum of all nodes: %d\n\n",sumOfAllNodes(root));
    printf("Input order for tree traversal:0 for preorder, 1 for inorder, 2 for postorder:");
    int trav;
    scanf("%d",&trav);
    traversal(root,trav);
    return 0;
}
