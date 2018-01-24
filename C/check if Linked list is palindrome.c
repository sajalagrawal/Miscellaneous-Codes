//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
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
bool isLLPalindrome(NODE *head){
    NODE *fastPtr=head;
    NODE *slowPtr=head;
    NODE *slowPrev=NULL;
    while(fastPtr && fastPtr->next){
        fastPtr=fastPtr->next->next;
        slowPrev=slowPtr;
        slowPtr=slowPtr->next;
    }
    //slowPrev now points to middle node
    NODE *secondHalfHead;
    if(fastPtr==NULL){
        secondHalfHead=slowPtr;
    }else{
        secondHalfHead=slowPtr->next;
    }
    secondHalfHead=reverseLL(secondHalfHead);
    NODE *cur1=head;
    NODE *cur2=secondHalfHead;
    slowPrev->next=NULL;
    while(cur1){
        //printf("%d %d\n",cur1->data,cur2->data);
        if(cur1->data!=cur2->data)return false;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return true;
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
    if(isLLPalindrome(head))printf("YES\n");
    else printf("NO\n");
    return 0;
}
