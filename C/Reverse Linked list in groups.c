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
void printLinkedList(NODE *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n");
}
NODE *reverseLL(NODE *head){
    NODE *prev=NULL;
    NODE *cur=head;
    NODE *nxt=NULL;
    while(cur){
        //printf("s=%d ",cur->data);
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}
NODE *reverseLLinGroups(NODE *head,int n){
    NODE *prev=NULL;
    NODE *cur=head;
    NODE *nxt=NULL;
    int count=0;
    while(count<n && cur){
        count++;
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    if(cur)head->next=reverseLLinGroups(cur,n);
    return prev;
}
int main()
{
    int len,n,i;
    printf("Enter no of nodes:");
    scanf("%d",&len);
    printf("Enter nodes:");
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
    //printLinkedList(head);
    printf("1. Reverse whole LL:\n");
    head=reverseLL(head);
    printLinkedList(head);
    head=reverseLL(head);
    printf("2. Reverse LL in parts:\n");
    printf("Reverse every n nodes, enter n:");
    scanf("%d",&n);
    head=reverseLLinGroups(head,n);
    printLinkedList(head);
    return 0;
}
