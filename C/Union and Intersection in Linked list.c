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
NODE *UnionHead=NULL;
NODE *UnionEnd=NULL;
NODE *InHead=NULL; //Intersection Head
NODE *InEnd=NULL; //Intersection End
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
NODE* findUnion(NODE* head1,NODE* head2){
    head1=sortLL(head1);
    head2=sortLL(head2);
    //printf("After sorting LL1:\n");
    //printLinkedList(head1);
    //printf("After sorting LL2:\n");
    //printLinkedList(head2);
    while(1){
        if(head1==NULL || head2==NULL)break;
        NODE* cur=(NODE*)malloc(sizeof(NODE));

        if(head1->data < head2->data){
            //printf("Checking %d and %d\n",head1->data,head2->data);
            cur->data=head1->data;
            head1=head1->next;
        }else if(head1->data > head2->data){
            //printf("Checking %d and %d\n",head1->data,head2->data);
            cur->data=head2->data;
            head2=head2->next;
        }else{
            //printf("Checking %d and %d\n",head1->data,head2->data);
            cur->data=head1->data;
            head1=head1->next;
            head2=head2->next;
        }

        if(UnionHead==NULL){
            UnionHead=cur;
            UnionHead->next=NULL;
            UnionEnd=UnionHead;
        }else if(UnionHead==UnionEnd){
            UnionHead->next=cur;
            UnionEnd=cur;
        }else{
            UnionEnd->next=cur;
            UnionEnd=cur;
        }
        UnionEnd->next=NULL;
    }

    while(head1){
        //printf("h1=%d\n",head1->data);
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        cur->data=head1->data;
        UnionEnd->next=cur;
        UnionEnd=cur;
        UnionEnd->next=NULL;
        head1=head1->next;
    }
    while(head2){
        //printf("h1=%d\n",head1->data);
        NODE *cur=(NODE*)malloc(sizeof(NODE));
        cur->data=head2->data;
        UnionEnd->next=cur;
        UnionEnd=cur;
        UnionEnd->next=NULL;
        head2=head2->next;
    }
    return UnionHead;
}

NODE* findIntersection(NODE* head1,NODE* head2){
    //both the LL are already sorted while taking union
    //printLinkedList(head1);
    //printLinkedList(head2);
    while(1){
        if(head1==NULL || head2==NULL)break;
        NODE* cur=(NODE*)malloc(sizeof(NODE));
        if(head1->data < head2->data){
            //printf("Checking %d and %d\n",head1->data,head2->data);
            head1=head1->next;
        }else if(head1->data > head2->data){
            //printf("Checking %d and %d\n",head1->data,head2->data);
            head2=head2->next;
        }else{
            //printf("Checking %d and %d\n",head1->data,head2->data);
            cur->data=head1->data;
            //printf("cur=%d\n",cur->data);
            head1=head1->next;
            head2=head2->next;

            if(InHead==NULL){
                InHead=cur;
                InHead->next=NULL;
                InEnd=InHead;
            }else if(InHead==InEnd){
                InHead->next=cur;
                InEnd=cur;
            }else{
                InEnd->next=cur;
                InEnd=cur;
            }
            InEnd->next=NULL;
        }
    }
    return InHead;
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
    UnionHead=findUnion(head1,head2);
    printf("Union:\n");
    printLinkedList(UnionHead);
    //printLinkedList(head1);
    //printLinkedList(head2);
    InHead=findIntersection(head1,head2);
    printf("Intersection:\n");
    printLinkedList(InHead);
    return 0;
}
