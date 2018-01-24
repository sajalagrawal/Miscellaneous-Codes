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
NODE *sortLL(NODE *head){//bubble sort
    NODE *last=NULL;
    NODE *ptr=head;
    int swapped=0,temp;
    do{
        swapped=0;
        ptr=head;
        while(ptr->next!=last){
            //printf("%d %d\n",ptr->data,ptr->next->data);
            if(ptr->data > ptr->next->data){
                temp=ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=temp;
                swapped=1;
            }
            //printf("%d %d\n",ptr->data,ptr->next->data);
            ptr=ptr->next;
        }
        last=ptr;
        //printf("last=%d\n",last->data);
    }while(swapped);
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
    head=sortLL(head);
    printLinkedList(head);
    return 0;
}
