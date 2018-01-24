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
NODE *start=NULL;
NODE *end=NULL;
NODE *head1=NULL;
NODE *last1=NULL;
NODE *head2=NULL;
NODE *last2=NULL;
void printLinkedList(NODE *head){
    if(head==NULL)printf("NULL\n");
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n");
}

NODE *mergeLL(NODE *head1,NODE *head2){
    NODE *cur;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    while(head1 && head2){
        //printf("h1=%d h2=%d\n",head1->data,head2->data);
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        if(head1->data < head2->data){
            cur->data=head1->data;
            head1=head1->next;
        }else{
            cur->data=head2->data;
            head2=head2->next;
        }
        if(start==NULL){
            start=cur;
            start->next=NULL;
            end=start;
        }else if(start==end){
            start->next=cur;
            end=cur;
        }else{
            end->next=cur;
            end=cur;
        }
        end->next=NULL;
    }
    while(head1){
        //printf("h1=%d\n",head1->data);
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        cur->data=head1->data;
        end->next=cur;
        end=cur;
        end->next=NULL;
        head1=head1->next;
    }
    while(head2){
        //printf("h2=%d\n",head2->data);
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        cur->data=head2->data;
        end->next=cur;
        end=cur;
        end->next=NULL;
        head2=head2->next;
    }
    return start;
}
int main()
{
    int len,n,i;
    printf("Enter no of nodes in first sorted LL:");
    scanf("%d",&len);
    printf("Enter nodes:");
    for(i=0;i<len;i++){
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        scanf("%d",&cur->data);
        //printf("%d ",cur->data);
        //singly LL
        if(head1==NULL){
            head1=cur;
            head1->next=NULL;
            last1=head1;
        }else if(head1==last1){
            head1->next=cur;
            last1=cur;
        }else{
            last1->next=cur;
            last1=cur;
        }
        last1->next=NULL;
    }
    printf("Enter no of nodes in second sorted LL:");
    scanf("%d",&len);
    printf("Enter nodes:");
    for(i=0;i<len;i++){
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        scanf("%d",&cur->data);
        //printf("%d ",cur->data);
        //singly LL
        if(head2==NULL){
            head2=cur;
            head2->next=NULL;
            last2=head2;
        }else if(head2==last2){
            head2->next=cur;
            last2=cur;
        }else{
            last2->next=cur;
            last2=cur;
        }
        last2->next=NULL;
    }
    //printLinkedList(head1);
    //printLinkedList(head2);
    start=mergeLL(head1,head2);
    printf("After mergingi:\n");
    printLinkedList(start);
    return 0;
}
