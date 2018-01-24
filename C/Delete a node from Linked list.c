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
    if(head==NULL)printf("NULL\n");
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n");
}
NODE *removeFromLL(NODE *head,int num){
    NODE *temp=head;
    //checking for head
    while(temp && temp->data==num){
        head=temp->next;
        free(temp);
        temp=head;
    }
    if(head==NULL)return;
    temp=head;
    NODE *prev=NULL;
    while(temp){
        prev=temp;
        temp=temp->next;
        while(temp && temp->data==num){
            prev->next=temp->next;
            free(temp);
            temp=prev->next;
        }
    }
    prev->next=NULL;
    return head;
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
    int num;
    printf("Enter node data to be deleted:");
    scanf("%d",&num);
    head=removeFromLL(head,num);
    printLinkedList(head);
    return 0;
}
