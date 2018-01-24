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
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n");
}
void deleteLL(NODE* head){
    NODE *cur=head,*temp=head;
    while(cur){
        temp=cur;
        cur=cur->next;
        free(temp);
    }
    head=NULL;
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
    deleteLL(head);
    return 0;
}
