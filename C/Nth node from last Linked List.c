//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE NODE;
NODE *head=NULL;
NODE *last=NULL;
NODE *NthNodeFromLast(NODE *head,int n){
    int len=0;
    NODE *cur=head;
    while(cur){
        len++;
        cur=cur->next;
    }
    if(n>len)return NULL;
    n=len-n;
    cur=head;
    while(n--){
        cur=cur->next;
    }
    return cur;
}
int main()
{
    int len,n,i;
    printf("Enter no of nodes:");
    scanf("%d",&len);
    for(i=0;i<len;i++){
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        scanf("%d",&cur->data);
        //printf("%d ",cur->data);
        //singly LL
        if(head==NULL){
            head=cur;
            head->next=NULL;
            last=head;
        }else if(head==last){
            head->next=cur;
            last=cur;
        }else{
            last->next=cur;
            last=cur;
        }
        last->next=NULL;
    }
    printf("Enter n:");
    scanf("%d",&n);
    NODE *ans=NthNodeFromLast(head,n);
    if(!ans){
        printf("NULL\n");
        return 0;
    }
    printf("Required Node: %d",ans->data);
    return 0;
}
