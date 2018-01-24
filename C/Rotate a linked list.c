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

NODE *rotateLL(NODE *head,int k){
    NODE *newHead=head;
    NODE *newEnd=NULL;
    NODE *cur=head;
    int len=0;
    while(cur){
        cur=cur->next;
        len++;
    }
    k=k%len;
    newEnd=head;
    k--;
    if(k<0)return head;
    while(k--){
        newEnd=newEnd->next;
    }
    newHead=newEnd->next;
    newEnd->next=NULL;
    cur=newHead;
    while(cur->next){
        cur=cur->next;
    }
    cur->next=head;
    return newHead;
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
    int k;
    printf("Enter k to rotate:");
    scanf("%d",&k);
    head=rotateLL(head,k);
    printLinkedList(head);
    return 0;
}
